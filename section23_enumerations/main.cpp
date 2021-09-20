#include <iostream>
#include <vector>

enum class Grocery_Item {Milk=350, Bread=250, Apple=132, Orange=100};

std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item){
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
    switch(grocery_item) {
        case Grocery_Item::Milk:
            os << "Milk";
            break;
        case Grocery_Item::Bread:
            os << "Bread";
            break;
        case Grocery_Item::Apple:
            os << "Apple";
            break;
        case Grocery_Item::Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid item";
    }
    os << " : " << value;
    return os; 
}


bool is_valid_grocery_item(Grocery_Item grocery_item){
    switch (grocery_item)
    {
    case Grocery_Item::Milk:
    case Grocery_Item::Apple:
    case Grocery_Item::Bread:
    case Grocery_Item::Orange:
        return true;
    default:
        return false;
    }
}

void display_grocery_list(const std::vector<Grocery_Item> &grocery_list){

    std::cout << "Grocery list" << "\n=============================" << std::endl;

    int invalid_item_count {0};
    int valid_item_count {0};

    for (Grocery_Item grocery_item : grocery_list){
        std::cout << grocery_item << std::endl;

        if (is_valid_grocery_item(grocery_item))
            ++valid_item_count;
        else 
            ++invalid_item_count;
    }

    std::cout << "===============================" << std::endl;
    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count+invalid_item_count << std::endl;
}


void test1(){
    std::cout << "\n---- Test 1 -----------------------\n" << std::endl;

    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);

    int Helicopter {1000};

    shopping_list.push_back(Grocery_Item(Helicopter));

    display_grocery_list(shopping_list);    
    
    
    
    
    
}


class Player{
    friend std::ostream &operator<< (std::ostream &os, const Player &p);
    
public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};

    Player(std::string name, Mode mode, Direction direction);

    std::string get_name();
    void set_name(std::string);

    Mode get_mode();
    void set_mode(Player::Mode);

    Direction get_direction();
    void set_direction(Player::Direction);
    
private:
    std::string name;
    Mode mode;
    Direction direction;
};

Player::Player(std::string name, Player::Mode mode, Player::Direction direction):
    name{name}, mode{mode}, direction{direction}{}





std::string get_player_mode(Player::Mode mode){
    switch(mode){
        case Player::Mode::Attack:
            return "Attack";
            break;
        case Player::Mode::Defense:
            return "Defense";
            break;
        case Player::Mode::Idle:
            return "Idle";
            break;
        default:
            return "Not acceptable mode";
    }
}

std::string get_player_direction(Player::Direction direction){
    switch(direction){
        case Player::Direction::North:
            return "North";
            break;
        case Player::Direction::South:
            return "South";
            break;
        case Player::Direction::East:
            return "East";
            break;
        case Player::Direction::West:
            return "West";
            break;
        default:
            return "Not acceptable direction";
    }
}

std::string Player::get_name(){
    return this->name;
}

void Player::set_name(std::string input){
    this->name = input;
}

Player::Mode Player::get_mode(){
    return this->mode;
}

void Player::set_mode(Player::Mode mode){
    this->mode = mode;
}

Player::Direction Player::get_direction(){
    return this->direction;
}

void Player::set_direction(Player::Direction direction){
    this->direction = direction;
}




std::ostream &operator<< (std::ostream &os, Player &p){
    os << "Player name:      " << p.get_name() << "\n"
       << "Player mode:      " << get_player_mode(p.get_mode()) << "\n"
       << "Player direction: " << get_player_direction(p.get_direction());
    return os;
}

template <typename T>
void display_players(std::vector<T> input){
    for (auto item:  input){
        std::cout << item << std::endl;
    }
}

void test2(){
    std::vector<Player> players;

    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::East};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::North};

    players.push_back(p1);
    players.push_back(p2);

    display_players(players);
}




int main(){


    // test1();
    test2();


    return 0;
}
