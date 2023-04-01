//
// Created by 25467 on 2023/4/1.
//

#include "leetcode831.h"


string leetcode831::maskPII(string s) {
    if(s.find('@')!=string::npos){
        return mask_mail(s);
    }else{
        return mask_phone(s);
    }
    return s;
}


string leetcode831::mask_mail(string &s) {
    string name;
    int index=0;
    while(index<s.size() && s[index]!='@'){
        name+=s[index];
        index++;
    }
    string res;
    res+=(char)std::tolower(name[0]);
    res+="*****";
    res+= (char)std::tolower(name[name.size()-1]);


    string doi=s.substr(index,s.size());
    for(char& c:doi){
        c=(char)std::tolower(c);
    }

    res+=doi;
    return res;

}


string leetcode831::mask_phone(string &s) {
    int count=0;
    string num_str;
    for(char& c:s){
        if(isalnum(c)){
            count++;
            num_str+=c;
        }
    }
    int country_code=count-10;

    string res;
    if(country_code!=0){
        res+='+';
        res.append(country_code,'*');
        res+='-';
    }

//拼接后半部分
    for(int i=0;i<2;i++){
        res+="***-";
    }
    res+=num_str.substr(country_code+6,num_str.size());
    return res;
}