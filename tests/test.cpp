#define CATCH_CONFIG_MAIN
#include <../include/catch.hpp>
#include "../include/compressor.hpp"

TEST_CASE("Encoding and Decoding Round-Trip - Standard Case") {
    Compressor c;
    std::string input = "AAAABBBCCDAA";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Long Repetitions") {
    Compressor c;
    std::string input = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBCC";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Short Input") {
    Compressor c;
    std::string input = "AAB";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Only Repetitions") {
    Compressor c;
    std::string input = "AAAA";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - No Repetitions") {
    Compressor c;
    std::string input = "ABCD";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - String of Digits") {
    Compressor c;
    std::string input = "12345";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Edge: Empty Input") {
    Compressor c;
    std::string input = "";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Single Character") {
    Compressor c;
    std::string input = "A";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Long String with No Repetition") {
    Compressor c;
    std::string input = "ABCDEFGHIJKLM";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Complex Repetition Pattern") {
    Compressor c;
    std::string input = "AABBCCDD";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

TEST_CASE("Encoding and Decoding Round-Trip - Alternating Characters") {
    Compressor c;
    std::string input = "ABABABAB";
    std::string encoded = c.encode(input);
    std::string decoded = c.decode(encoded);
    REQUIRE(input == decoded);
}

