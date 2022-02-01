#include "../headers/inbox.hpp"

Inbox::Inbox() = default;

void Inbox::store_in_timeline(Tweet* tweet) {
    this->timeline[tweet->get_id()] = tweet;
}

void Inbox::store_in_my_tweets(Tweet* tweet) {
    this->my_tweets[tweet->get_id()] = tweet;
}

void Inbox::rm_msgs_from(const std::string& username) {
    std::map<int, Tweet*, std::greater<int>>::iterator it = this->timeline.begin();
    while (it != this->timeline.end()) {
        if (it->second->get_username() == username) {
            this->timeline.erase(it++);
        } else {
            it++;
        }
    }
}

std::map<int, Tweet*, std::greater<int>> Inbox::get_timeline() {
    return this->timeline;
}

std::map<int, Tweet*, std::greater<int>> Inbox::get_my_tweets() {
    return this->my_tweets;
}

Tweet* Inbox::get_tweet(int id) {
    if (this->timeline.count(id) == 1) {
        return this->timeline[id];
    } else if (this->my_tweets.count(id) == 1) {
        return this->my_tweets[id];
    }

    throw TweetException("fail: tweet not found in this user inbox");
}

std::ostream& operator<<(std::ostream& os, Inbox& inbox) {
    for (auto& msg : inbox.get_timeline()) {
        os << *msg.second << std::endl;
    }

    return os;
}