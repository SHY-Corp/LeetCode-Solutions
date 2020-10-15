/*
Defanging an IP Address-
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Problem link- https://leetcode.com/problems/defanging-an-ip-address/

Approach-
Traversing through the string, and adding a [ to the defanged IP Address everytime a . is encountered
A ] is added after adding the .
*/

#incldue<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string defangIPAddress(string IPAddress)
    {
        string defangedIPAddress;

        int currentPosition=0;          //This variable will keep track of the position where the next character has to be added in defangedIPAddress
        for(int i=0;IPAddress[i]!='\0';i++)
        {
            if(IPAddress[i]=='.')   //converts . to [.] in the string defangedIPAddress
            {
                defangedIPAddress[currentPosition]='[';
                currentPosition++;
                defangedIPAddress[currentPosition]='.';
                currentPosition++;
                defangedIPAddress[currentPosition]=']';
                currentPosition++;
            }
            else
            {
                defangedIPAddress[currentPosition]=IPAddress[i];    //copies every number from IPAddress to defangedIPAddress
                currentPosition++;
            }
        }
        return defangedIPAddress;
    }
};
