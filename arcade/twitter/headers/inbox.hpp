#pragma once

#include <iostream>
#include <map>
#include "tweet.hpp"

class Inbox {
public:
    Inbox();

    void store_in_timeline(Tweet* tweet);
    void store_in_my_tweets(Tweet* tweet);
    void rm_msgs_from(const std::string& username);

    std::map<int, Tweet*, std::greater<int>> get_timeline();
    std::map<int, Tweet*, std::greater<int>> get_my_tweets();
    Tweet* get_tweet(int id);

    friend std::ostream& operator<<(std::ostream& os, Inbox& inbox);
    
private:
    std::map<int, Tweet*, std::greater<int>> timeline;
    std::map<int, Tweet*, std::greater<int>> my_tweets;
};