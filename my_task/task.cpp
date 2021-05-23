#include "task.h"
using namespace testspace;



uint8_t Hamming74::sum4BitsMod2(uint8_t x)
{
    return (((x & 8) >> 3) ^ ((x & 16) >> 4) ^ ((x & 32) >> 5) ^ ((x & 64) >> 6));
}

std::vector<uint8_t> Hamming74::Encode(std::vector<uint8_t> const& data) {
    size_t out_size;
    if (data.size() % 4 == 0)
        out_size = (data.size() * 7) / 4;

    else
        out_size = (data.size() * 7) / 4 + 1;


    std::vector<uint8_t>  out_data(out_size);
    int NumbRecordedBits = 0;
    uint8_t x;

    for (int i = 0; i < data.size() * 2; i++)
    {
        if (i % 2 == 0) {
            x = (15 & data[i / 2]) << 3;
        }
        else {
            x = (240 & data[i / 2]) >> 1;
        }

        x = x | sum4BitsMod2(x & 104) | (sum4BitsMod2(x & 56) << 1) | (sum4BitsMod2(x & 112) << 2);

        out_data[NumbRecordedBits / 8] = out_data[NumbRecordedBits / 8] | (x << (NumbRecordedBits % 8));


        if (NumbRecordedBits % 8 > 1)
        {
            int ost = 8 - NumbRecordedBits % 8;
            out_data[NumbRecordedBits / 8 + 1] = x >> ost;
        }
        NumbRecordedBits += 7;
    }

    return out_data;
}
Hamming74::~Hamming74() {}



std::vector<uint8_t> DiffCode::Encode(std::vector<uint8_t> const& data) {

    std::vector<uint8_t>  out_data(data.size());

    out_data[0] = (0 ^ data[0]);
    for (int j = 1; j < 8; j++)
    {
        out_data[0] = (out_data[0] << 1 ^ data[0]);
    }


    for (int i = 1; i < data.size(); i++)
    {
        out_data[i] = ((out_data[i - 1] >> 7) ^ data[i]) & 1;
        for (int j = 1; j < 8; j++)
        {
            out_data[i] = out_data[i] | ((out_data[i] << 1) ^ data[i]) & (1 << j);
        }

    }
    return out_data;
}
DiffCode::~DiffCode() {};