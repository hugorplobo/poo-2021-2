#include "../headers/tweet.hpp"
#include "../headers/colors.hpp"

Tweet::Tweet(int id, const std::string& username, const std::string& msg)
: id {id}, username {username}, msg {msg} {
    this->deleted = false;
    this->rt_from = nullptr;
}

void Tweet::like(const std::string& username) {
    this->likes.insert(username);
}

int Tweet::get_id() const {
    return this->id;
}

std::string Tweet::get_msg() const {
    return this->msg;
}

std::string Tweet::get_username() const {
    return this->username;
}

std::set<std::string> Tweet::get_likes() const {
    return this->likes;
}

bool Tweet::is_deleted() const {
    return this->deleted;
}

void Tweet::set_deleted(bool deleted) {
    this->deleted = deleted;
}

void Tweet::set_rt(Tweet* tweet) {
    this->rt_from = tweet;
}

std::ostream& operator<<(std::ostream& os, Tweet& tweet) {
    Tweet* next_rt = &tweet;
    int depth = 0;

    do {
        if (next_rt->deleted) {
            os << std::string(depth * 2, ' ') << colors::faint << "Esse tweet foi apagado - ID: " << next_rt->get_id() << colors::reset << std::endl;
        } else {
            os << std::string(depth * 2, ' ') << colors::blue << "@" << next_rt->get_username() << colors::reset << ":" << next_rt->get_msg();
            os << " [ ";

            for (auto& user : next_rt->likes) {
                os << colors::blue << "@" << user << colors::reset << (user == *(--next_rt->likes.end()) ? " " : ", ");
            }

            os << "]" << colors::reset << " - ID: " << next_rt->get_id() << std::endl;
        }

        next_rt = next_rt->rt_from;
        depth++;
    } while (next_rt != nullptr);

    return os;
}

TweetException::TweetException(const std::string& message) : message {message} {}

const char* TweetException::what() const noexcept {
    return this->message.c_str();
}
