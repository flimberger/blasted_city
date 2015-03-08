set(blasted_city_game_SRCS
    Bullet.cpp
  Clothes.cc
  Entity.cc
  Inventory.cc
  Item.cc
  Map.cc
  Soldier.cc
  Weapon.cc
  World.cc
  classes/Burner.cc
  classes/Gunner.cc
  classes/Sniper.cc
)

add_library(game STATIC ${blasted_city_game_SRCS})
