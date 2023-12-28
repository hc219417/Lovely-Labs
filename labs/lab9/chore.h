/**
 *   @file: chore.h
 * @author: Hannah Culver
 *   @date: March 20, 2022
 *  @brief: lab 9 (stacks and queues)
 */

#ifndef CHORE
#define CHORE

#include <queue>
#include <string>
#include <iostream>

class Chore{
    public:
        Chore(){chore = "N/A", prnum = -1;}

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        friend bool operator < (const Chore& a, const Chore& b);

    private:
        std::string chore;
        int prnum;
};

std::ostream& operator << (std::ostream outs, const Chore& c);
std::istream& operator >> (std::istream& ins, Chore& c);

#endif