#include "mid/mid.h"
#include "low/low.h"

#include <iostream>

#include <fmt/core.h>
#include <fmt/color.h>

void print_message() {
    auto msg = message();
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "{}\n", msg);
}
