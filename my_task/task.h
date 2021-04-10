// my_sin.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "vector"
namespace testspace {

    class ParentClass
    {
    public:
        virtual std::vector<uint8_t> Encode(std::vector<uint8_t> const& data) = 0;
    };


    class Hamming74 :public ParentClass
    {
    private:
        uint8_t sum4BitsMod2(uint8_t x);
    public:
        virtual std::vector<uint8_t> Encode(std::vector<uint8_t> const& data);
    };


    class DiffCode :public ParentClass
    {

    public:
        virtual std::vector<uint8_t> Encode(std::vector<uint8_t> const& data);
    };



}