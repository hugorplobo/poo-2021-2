#include "../headers/controller.hpp"

Controller::Controller() {
    this->next_tweet_id = 0;
}

Tweet* Controller::create_twitter(const std::string& username, const std::string& msg) {
    Tweet* tweet = new Tweet(this->next_tweet_id, username, msg);
    this->tweets[this->next_tweet_id++] = tweet;
    return tweet;
}

void Controller::add_user(const std::string& username) {
    User* user = new User(username);
    if (this->users.count(username) == 1) {
        throw TweetException("fail: username already exists");
    }
    this->users[username] = user;
}

void Controller::send_tweet(const std::string& username, const std::string& msg) {
    Tweet* tweet = this->create_twitter(username, msg);
    this->get_user(username)->send_tweet(tweet);
}

void Controller::send_rt(const std::string& username, int tweet_id, const std::string& msg) {
    Tweet* tweet = this->create_twitter(username, msg);
    User* user = this->get_user(username);
    tweet->set_rt(user->get_inbox().get_tweet(tweet_id));
    user->send_tweet(tweet);
}

void Controller::rm_user(const std::string& username) {
    User* user = this->get_user(username);
    user->unfollow_all();
    user->reject_all();
    
    for (auto& msg : user->get_inbox().get_my_tweets()) {
        msg.second->set_deleted(true);
    }

    delete user;
    this->users.erase(this->users.find(username));
}

User* Controller::get_user(const std::string& username) {
    if (this->users.count(username) == 1) {
        return this->users[username];
    }

    throw TweetException("fail: user not found");
}

Tweet* Controller::get_tweet(int tweet_id) {
    if (this->tweets.count(tweet_id) == 1) {
        return this->tweets[tweet_id];
    }

    throw TweetException("fail: tweet not found");
}

std::ostream& operator<<(std::ostream& os, Controller& controller) {
    for (auto& user : controller.users) {
        os << *user.second;
    }

    return os;
}