#include "../headers/user.hpp"
#include "../headers/colors.hpp"

User::User(const std::string& username)
: username {username} {}

void User::follow(User* to_follow) {
    this->following[to_follow->username] = to_follow;
    to_follow->followers[this->username] = this;
}

void User::unfollow(User* to_unfollow) {
    auto iterator_to_unfollow = this->following.find(to_unfollow->username);
    if (iterator_to_unfollow != this->following.end()) {
        this->inbox.rm_msgs_from(to_unfollow->username);
        this->following.erase(iterator_to_unfollow);
        to_unfollow->followers.erase(to_unfollow->followers.find(this->username));
        return;
    }

    throw TweetException("fail: must follow the user to unfollow it");
}

void User::send_tweet(Tweet* tweet) {
    this->inbox.store_in_my_tweets(tweet);
    this->inbox.store_in_timeline(tweet);

    for (auto& user : this->followers) {
        user.second->inbox.store_in_timeline(tweet);
    }
}

void User::like(int tweet_id) {
    auto tweet = this->inbox.get_tweet(tweet_id);
    if (tweet != nullptr) {
        tweet->like(this->username);
        return;
    }

    throw TweetException("fail: tweet not found in this user inbox");
}

void User::unfollow_all() {
    std::map<std::string, User*>::iterator it = this->following.begin();
    while (it != this->following.end()) {
        this->unfollow((it++)->second);
    }
}

void User::reject_all() {
    std::map<std::string, User*>::iterator it = this->followers.begin();
    while (it != this->followers.end()) {
        (it++)->second->unfollow(this);
    }
}

Inbox& User::get_inbox() {
    return this->inbox;
}

std::string User::get_username() {
    return this->username;
}

std::map<std::string, User*> User::get_followers() {
    return this->followers;
}

std::map<std::string, User*> User::get_following() {
    return this->following;
}

std::ostream& operator<<(std::ostream& os, User& user) {
    auto following = user.get_following();
    auto followers = user.get_followers();

    os << colors::blue << "@" << user.get_username() << colors::reset;
    os << "\n\t" << "Seguindo:   [ ";

    for (auto& user : following) {
        os << colors::blue << "@" << user.second->get_username() << colors::reset << (user == *(--following.end()) ? " " : ", ");
    }

    os << "]\n\t" << "Seguidores: [ ";

    for (auto& user : followers) {
        os << colors::blue << "@" << user.second->get_username() << colors::reset << (user == *(--followers.end()) ? " " : ", ");
    }

    os << "]\n";

    return os;
}