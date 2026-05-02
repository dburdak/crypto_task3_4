#include <gtest/gtest.h>
#include "../hash_func.h"
#include <vector>

TEST(SHA256Test, VectorABC) {
    std::vector<uint8_t> msg = {'a', 'b', 'c'};

    uint32_t expected[8] = {
        0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223,
        0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad
    };

    uint32_t out[8];
    hash_counting(msg, out);

    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(out[i], expected[i]);
    }
}

TEST(SHA256Test, Empty) {
    std::vector<uint8_t> msg = {};

    uint32_t expected[8] = {
        0xe3b0c442, 0x98fc1c14, 0x9afbf4c8, 0x996fb924,
        0x27ae41e4, 0x649b934c, 0xa495991b, 0x7852b855
    };
    uint32_t actual[8];

    hash_counting(msg, actual);

    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(SHA256Test, TestVector3) {
    std::string s = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    std::vector<uint8_t> msg(s.begin(), s.end());

    uint32_t expected[8] = {
        0x248d6a61, 0xd20638b8, 0xe5c02693, 0x0c3e6039,
        0xa33ce459, 0x64ff2167, 0xf6ecedd4, 0x19db06c1
    };
    uint32_t actual[8];

    hash_counting(msg, actual);

    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(SHA256Test, TestVector4) {
    std::string s = "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu";
    std::vector<uint8_t> msg(s.begin(), s.end());

    uint32_t expected[8] = {
        0xcf5b16a7, 0x78af8380, 0x036ce59e, 0x7b049237,
        0x0b249b11, 0xe8f07a51, 0xafac4503, 0x7afee9d1
    };
    uint32_t actual[8];

    hash_counting(msg, actual);

    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}

TEST(SHA256Test, TestVector5) {
    std::vector<uint8_t> msg(1000000, 'a');

    uint32_t expected[8] = {
        0xcdc76e5c, 0x9914fb92, 0x81a1c7e2, 0x84d73e67,
        0xf1809a48, 0xa497200e, 0x046d39cc, 0xc7112cd0
    };
    uint32_t actual[8];

    hash_counting(msg, actual);

    for (int i = 0; i < 8; ++i) {
        EXPECT_EQ(actual[i], expected[i]);
    }
}
