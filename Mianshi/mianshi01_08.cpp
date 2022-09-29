//
// Created by skt on 2022/9/30.
//

#include "mianshi01_08.h"

void mianshi01_08::setZeroes(vector<vector<int>> &matrix) {
//    int count=0;
//    int n=matrix.size();
//    int m=matrix[0].size();
//    vector<int> cor[2];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            if(matrix[i][j]==0){
//                count++;
//                cor[0].push_back(i);
//                cor[1].push_back(j);
//            }
//        }
//    }
    int n=matrix.size();
    int m=matrix[0].size();
    //讨论第一行第一列需不需要清0
    bool flagCol=false,flagRow= false;
    for(int i=0;i<m;i++){
        if(matrix[0][i]==0){
            flagRow=true;
        }
    }
    //special
    for(int i=0;i<n;i++){
        if(matrix[i][0]==0){
            flagCol=true;
        }
    }
    if((m<2&&flagCol)||(n<2&&flagRow)){
        matrix.assign(n,vector<int>(m,0));
    }
    //use 1col 1row to
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++){
        if(matrix[0][i]==0){
            for(int j=0;j<n;j++){
                matrix[j][i]=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(matrix[i][0]==0){
            matrix[i].assign(m,0);
        }
    }
    if(flagRow){
        matrix[0].assign(m,0);
    }
    if(flagCol){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }

}

std::ostream &mianshi01_08::operator<<(const vector<vector<int>> &mat) {
    for(vector<vector<int>>::const_iterator it=mat.begin();it!=mat.end();it++){
        for(vector<int>::const_iterator cit=(*it).begin();cit!=(*it).end();cit++){
            std::cout<<*cit<<" ";
        }
        std::cout<<std::endl;
    }
}