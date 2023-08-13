#ifndef wavwrite_hpp
#define wavwrite_hpp

#include <cstdio>

class wav_file_writer{
public:
    wav_file_writer(const char* filename, long frequency);
    ~wav_file_writer();
    void close();
    void write(short* data, std::size_t n);
    unsigned long get_written_bytes(){ return header.data_size; }
private:
    typedef unsigned short uint16_t;
    typedef unsigned long uint32_t;
    std::FILE* fp;
#pragma pack(push, 1)
    struct wavefileheader_t{
        char riff[4];
        uint32_t riff_size;
        char wave[4];
        char fmt_[4];
        uint32_t fmt_size;
        uint16_t format_tag;
        uint16_t channels;
        uint32_t samples_per_sec;
        uint32_t avg_bytes_per_sec;
        uint16_t block_align;
        uint16_t bits_per_sample;
        char data[4];
        uint32_t data_size;
    }header;
#pragma pack(pop)
};

#endif
