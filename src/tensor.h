#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Tensor{
    public:
        vector<float> data;
        int rows,cols;
        Tensor(int x,int y);
        float& operator()(int i,int j);
        void print();
    };
vector<float> vector_add(vector<float> a,vector<float> b);
void scalar_mul(vector<float> &a,float s);
Tensor mat_mul(Tensor &a,Tensor &b);
Tensor transpose(Tensor &a);