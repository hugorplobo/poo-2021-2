#pragma once

#include <iostream>
#include <set>

class Tweet {
public:
    Tweet(int id, const std::string& username, const std::string& msg);
    ~Tweet();

    void like(const std::string& username);

    int get_id() const;
    std::string get_msg() const;
    std::string get_username() const;
    std::set<std::string> get_likes() const;
    bool is_deleted() const;
    void set_rt(Tweet* tweet);
    void set_deleted(bool deleted);

    friend std::ostream& operator<<(std::ostream& os, Tweet& tweet);
    friend void print_recursive(Tweet& tweet, int depth);

private:
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    Tweet* rt_from;
    bool deleted;
};

class TweetException : public std::exception {
public:
    TweetException(const std::string& message);
    const char* what() const noexcept override;
private:
    std::string message;
};