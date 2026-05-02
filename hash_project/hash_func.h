#pragma once
#include <bit>
#include <array>


uint32_t ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t maj(uint32_t x, uint32_t y, uint32_t z);

uint32_t rotr(uint32_t x, uint32_t n);

void add_padding(std::vector<uint8_t> &message);

void hash_counting(std::vector<uint8_t> message, uint32_t out_hash[8]);
void task2();



