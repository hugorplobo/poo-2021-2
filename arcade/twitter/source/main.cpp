#include "../headers/controller.hpp"
#include "../headers/colors.hpp"

int main() {
    Controller sistema;

    std::cout << colors::bold << colors::blue << "- Twitter CLI\n" << std::endl;

    while (true) {
        std::string cmd;
        std::cout << colors::bold << colors::bright_yellow << "$ " << colors::reset;
        std::cin >> cmd;

        try {
            if (cmd == "exit" || cmd == "e") {
                break;
            } else if (cmd == "add" || cmd == "a") {
                std::string username;
                std::cin >> username;
                sistema.add_user(username);
            } else if (cmd == "show" || cmd == "s") {
                std::cout << "\n" << sistema << std::endl;
            } else if (cmd == "follow" || cmd == "f") {
                std::string following, to_follow;
                std::cin >> following >> to_follow;
                sistema.get_user(following)->follow(sistema.get_user(to_follow));
            } else if (cmd == "unfollow" || cmd == "u") {
                std::string unfollowing, to_unfollow;
                std::cin >> unfollowing >> to_unfollow;
                sistema.get_user(unfollowing)->unfollow(sistema.get_user(to_unfollow));
            } else if (cmd == "twittar" || cmd == "t") {
                std::string username, msg;
                std::cin >> username;
                std::getline(std::cin, msg);
                sistema.send_tweet(username, msg);
            } else if (cmd == "retwittar" || cmd == "rt") {
                int msg_id;
                std::string username, rt;
                std::cin >> username >> msg_id;
                std::getline(std::cin, rt);
                sistema.send_rt(username, msg_id, rt);
            } else if (cmd == "timeline" || cmd == "tl") {
                std::string username;
                std::cin >> username;
                std::cout << sistema.get_user(username)->get_inbox();
            } else if (cmd == "remove" || cmd == "rm") {
                std::string username;
                std::cin >> username;
                sistema.rm_user(username);
            } else if (cmd == "like" || cmd == "l") {
                std::string username;
                int tweet_id;
                std::cin >> username >> tweet_id;
                sistema.get_user(username)->like(tweet_id);
            } else if (cmd == "clear" || cmd == "c") {
                #if defined(_WIN32) || defined(_WIN64)
                    std::system("cls");
                #else
                    std::system("clear");
                #endif
            } else {
                std::cout << colors::bright_red << "fail: command not found" << colors::reset << std::endl;
            }
        } catch (TweetException& err) {
            std::cout << colors::bright_red << err.what() << colors::reset << std::endl;
        }
    }
}