// Question :- To convert a integer number into the roman

// Implementation
class Solution {
public:
    string intToRoman(int num) {    // num is considered as number 
        string roman = "";  // Taken a empty string which stores the roman
        
        while(num != 0){  //checks if the number is not equal to 0, if it is not equal then there is more processing to be done
            if(num >= 1000){  //if the number is larger than 1000, then add an M to the roman string and subtract 1000 from number
                roman += "M";
                num -= 1000;
            }
            else if(num >= 900){  //if the number is larger than 900, then add an CM to the roman string and subtract 900 from number
                roman += "CM";
                num -= 900;
            }
            else if(num >= 500){  //if the number is larger than 500, then add an D to the roman string and subtract 500 from number
                roman += "D";
                num -= 500;
            }
            else if(num >= 400){  //if the number is larger than 400, then add an CD to the roman string and subtract 400 from number
                roman += "CD";
                num -= 400;
            }
            else if(num >= 100){  //if the number is larger than 100, then add an C to the roman string and subtract 100 from number
                roman += "C";
                num -= 100;
            }
            else if(num >= 90){  //if the number is larger than 90, then add an XC to the roman string and subtract 90 from number
                roman += "XC";
                num -= 90;
            }
            else if(num >= 50){  //if the number is larger than 50, then add an L to the roman string and subtract 50 from number
                roman += "L";
                num -= 50;
            }
            else if(num >= 40){  //if the number is larger than 40, then add an XL to the roman string and subtract 40 from number
                roman += "XL";
                num -= 40;
            }
            else if(num >= 10){  //if the number is larger than 10, then add an X to the roman string and subtract 10 from number
                roman += "X";
                num -= 10;
            }
            else if(num >= 9){  //if the number is larger than 9, then add an IX to the roman string and subtract 9 from number
                roman += "IX";
                num -= 9;
            }
            else if(num >= 5){  //if the number is larger than 5, then add an V to the roman string and subtract 5 from number
                roman += "V";
                num -= 5;
            }
            else if(num >= 4){  //if the number is larger than 4, then add an IV to the roman string and subtract 4 from number
                roman += "IV";
                num -= 4;
            }
            else if(num >= 1){  //if the number is larger than 1, then add an I to the roman string and subtract 1 from number
                roman += "I";
                num -= 1;
            }
        }
        return roman;	// returning the roman
    }
};
