# include "../src/tensor.h"
Tensor::Tensor(int r,int c){
    rows=r;
    cols=c;
    data.resize(rows*cols);
}
float& Tensor::operator()(int i,int j){
    return data[i*cols+j];
}
void Tensor::print(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<data[i*cols+j]<<" ";
        }
        cout<<"\n";
    }
}
vector<float> vector_add(vector<float> a,vector<float> b){
    vector<float> c(a.size());
    for(int i=0;i<a.size();i++){
        c[i]=a[i]+b[i];
    }
    return c;
}
void scalar_mul(vector<float> &a,float s){
    for(auto &i:a){
        i*=s;
    }
}
Tensor mat_mul(Tensor &a,Tensor &b){
    Tensor c(a.rows,b.cols);
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<b.cols;j++){
            c(i,j)=0.0f;
            for(int k=0;k<a.cols;k++){
                c(i,j)+=a(i,k)*b(k,j);
            }
        }
    }
    return c;
}
Tensor transpose(Tensor &a){
    Tensor c(a.cols,a.rows);
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            c(j,i)=a(i,j);
        }
    }
    return c;
}