
#pragma once

#include "vector"
namespace testspace {

    class ICoder
    {
    public:
        virtual std::vector<uint8_t> Encode(std::vector<uint8_t> const& data) = 0;
    };


    class Hamming74 :public ICoder
    {
    private:
        uint8_t sum4BitsMod2(uint8_t x);
    public:
        std::vector<uint8_t> Encode(std::vector<uint8_t> const& data) override;
    };


    class DiffCode :public ICoder
    {

    public:
        virtual std::vector<uint8_t> Encode(std::vector<uint8_t> const& data) override;
    };



}