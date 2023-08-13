#include "wavwrite.hpp"

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

using namespace std;

wav_file_writer::wav_file_writer(const char* filename, long frequency)
{
    std::memcpy(header.riff, "RIFF", 4);
    header.riff_size = 0;
    std::memcpy(header.wave, "WAVE", 4);
    std::memcpy(header.fmt_, "fmt ", 4);
    header.fmt_size = 16;
    header.format_tag = 1;
    header.channels = 2;
    header.bits_per_sample = 16;
    header.samples_per_sec = frequency;
    header.block_align = static_cast<uint16_t>(header.channels * header.bits_per_sample / 8);
    header.avg_bytes_per_sec = header.block_align * header.samples_per_sec;
    std::memcpy(header.data, "data", 4);
    header.data_size = 0;

    fp = std::fopen(filename, "wb");
    if(!fp){
        throw std::runtime_error(std::strerror(errno));
    }
    std::fwrite(&header, sizeof(header), 1, fp);
}

wav_file_writer::~wav_file_writer()
{
    std::fclose(fp);
}

void wav_file_writer::write(short* data, std::size_t n)
{
    n *= sizeof(short[2]);
    std::fwrite(data, 1, n, fp);
    header.data_size += n;
    if(ferror(fp)){
        throw std::runtime_error("write error");
    }
}

void wav_file_writer::close()
{
    header.riff_size = sizeof(wavefileheader_t) + header.data_size - 8;
    std::fseek(fp, 0, SEEK_SET);
    std::fwrite(&header, sizeof(header), 1, fp);
    std::fseek(fp, 0, SEEK_END);
    std::fflush(fp);
    if(ferror(fp)){
        throw std::runtime_error("write error");
    }
}

