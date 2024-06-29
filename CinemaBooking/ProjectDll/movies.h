#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
public:
    Movie(int id, std::string name, std::vector<std::string> showTimes)
        : id(id), name(name), showTimes(showTimes) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::vector<std::string> getShowTimes() const { return showTimes; }

private:
    int id;
    std::string name;
    std::vector<std::string> showTimes;
};

void Burgas();

#endif // MOVIE_H