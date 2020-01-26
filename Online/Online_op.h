/*
Copyright (c) 2017, The University of Bristol, Senate House, Tyndall Avenue, Bristol, BS8 1TH, United Kingdom.
Copyright (c) 2019, COSIC-KU Leuven, Kasteelpark Arenberg 10, bus 2452, B-3001 Leuven-Heverlee, Belgium.

All rights reserved
*/
#ifndef _OnlineOP
#define _OnlineOP

#include "Offline/offline_data.h"
#include "Online/Machine.h"
#include "System/Player.h"
#include "Processor/Processor.h"

extern vector<sacrificed_data> SacrificeD;
/*
void online_phase(int online_num, Player &P, offline_control_data &OCD,
                  Machine &machine);
*/

enum
{
    TRIPLE = 0x50,
    BIT = 0x51,
    SQUARE = 0x52,
    INPUT_MASK = 0x53
};

class OnlineOp
{
public:
    Processor &Proc;
    int online_num;
    Player &P;
    offline_control_data &OCD;
    Machine &machine;
    explicit OnlineOp(Processor &Proc_, int online_num_, Player &P_, offline_control_data &OCD_, Machine &machine_)
        : Proc(Proc_), online_num(online_num_), P(P_), OCD(OCD_), machine(machine_)
    {
    }
    int verbose = 2;

    // a + b = c
    void add(Share &a, Share &b, Share &c);
    // a * b = c
    void mul(Share &a, Share &b, Share &c);
    // a / b = c (mod q)
    void div(Share &a, Share &b, Share &c);
    // vs --> vc
    void open(const vector<Share> &vs, vector<gfp> &vc);

    // secrets, clears
    void reveal(const vector<Share> &vs, vector<gfp> &vc);
    void reveal_and_print(const vector<Share> &vs, vector<gfp> &vc);
    void reveal_and_print(const vector<Share> &vs);

    void get_inputs(vector<Share> &inputs);
    void get_inputs_dumy(vector<Share> &inputs);

    // the following apis for testing
    void test_add();
    void test_mul();
    void test_div();
};

#endif
