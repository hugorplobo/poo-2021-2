#pragma once

#include <iostream>
#include <map>
#include "tweet.hpp"
#include "user.hpp"

class Controller {
public:
    Controller();

    void add_user(const std::string& username);
    void send_tweet(const std::string& username, const std::string& msg);
    void send_rt(const std::string& username, int tweet_id, const std::string& msg);
    void rm_user(const std::string& username);

    User* get_user(const std::string& username);
    Tweet* get_tweet(int tweet_id);

    friend std::ostream& operator<<(std::ostream& os, Controller& controller);

private:
    int next_tweet_id;
    std::map<int, Tweet*> tweets;
    std::map<std::string, User*> users;

    Tweet* create_twitter(const std::string& username, const std::string& msg);
};