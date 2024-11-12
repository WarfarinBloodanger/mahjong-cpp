#include "mahjong/mahjong.hpp"

using namespace mahjong;

int main(int, char **)
{
    // calc() に手牌を指定した場合、通常手、七対子手、国士無双手の向聴数を計算し、
    // 向聴数が最小となる手の種類及び向聴数をタプルで返します。
    {
        Hand hand({Tile::Manzu1, Tile::Manzu1, Tile::Manzu1, Tile::Manzu2,
                   Tile::RedManzu5, Tile::Manzu6, Tile::Manzu7, Tile::Manzu8,
                   Tile::Manzu9, Tile::Pinzu1, Tile::Pinzu1, Tile::Pinzu2,
                   Tile::Pinzu2});

        auto [syanten_type, syanten] = ShantenCalculator::calc(hand);

        std::cout << fmt::format("手牌: {}, 向聴数の種類: {}, 向聴数: {}",
                                 hand.to_string(), SyantenType::Name[syanten_type],
                                 syanten)
                  << std::endl;
    }

    // 特定の手の向聴数を計算したい場合は第2引数にフラグで指定します。フラグは複数指定できます。
    // calc(hand, SyantenType::Normal) 通常手の向聴数を計算する。
    // calc(hand, SyantenType::Normal | SyantenType::Tiitoi)
    // 通常手及び七対子手の向聴数を計算する。

    // 一般手の向聴数を計算する
    {
        Hand hand({Tile::Manzu1, Tile::Manzu1, Tile::Manzu1, Tile::Manzu2,
                   Tile::RedManzu5, Tile::Manzu6, Tile::Manzu7, Tile::Manzu8,
                   Tile::Manzu9, Tile::Pinzu1, Tile::Pinzu1, Tile::Pinzu2,
                   Tile::Pinzu2});

        auto [syanten_type, syanten] =
            ShantenCalculator::calc(hand, SyantenType::Normal);

        std::cout << fmt::format("手牌: {}, 向聴数の種類: {}, 向聴数: {}",
                                 hand.to_string(), SyantenType::Name[syanten_type],
                                 syanten)
                  << std::endl;
    }

    // 七対子手の向聴数を計算する
    {
        Hand hand({Tile::Manzu1, Tile::Manzu1, Tile::Manzu2, Tile::Manzu2,
                   Tile::RedManzu5, Tile::Manzu6, Tile::Manzu7, Tile::Manzu8,
                   Tile::Manzu9, Tile::Pinzu1, Tile::Pinzu1, Tile::Pinzu2,
                   Tile::Pinzu2});

        auto [syanten_type, syanten] =
            ShantenCalculator::calc(hand, SyantenType::Tiitoi);

        std::cout << fmt::format("手牌: {}, 向聴数の種類: {}, 向聴数: {}",
                                 hand.to_string(), SyantenType::Name[syanten_type],
                                 syanten)
                  << std::endl;
    }

    // 国士無双手の向聴数を計算する
    {
        Hand hand({Tile::Manzu1, Tile::Manzu1, Tile::Manzu2, Tile::Manzu2,
                   Tile::RedManzu5, Tile::Manzu6, Tile::Manzu7, Tile::Manzu8,
                   Tile::Manzu9, Tile::Pinzu1, Tile::East, Tile::South, Tile::West});

        auto [syanten_type, syanten] =
            ShantenCalculator::calc(hand, SyantenType::Kokusi);

        std::cout << fmt::format("手牌: {}, 向聴数の種類: {}, 向聴数: {}",
                                 hand.to_string(), SyantenType::Name[syanten_type],
                                 syanten)
                  << std::endl;
    }
}
