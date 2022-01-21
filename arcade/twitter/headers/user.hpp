#pragma once

#include <iostream>
#include <map>
#include "inbox.hpp"

class User {
public:
    User(const std::string& username);

    void follow(User* to_follow);
    void receive_follow(User* followed);
    void send_tweet(Tweet* tweet);
    void unfollow(User* to_unfollow);
    void receive_unfollow(User* unfollowed);
    void like(int tweet_id);
    void unfollow_all();
    void reject_all();

    std::string get_username();
    std::map<std::string, User*> get_followers();
    std::map<std::string, User*> get_following();
    Inbox& get_inbox();

    friend std::ostream& operator<<(std::ostream& os, User& user);

private:
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
};