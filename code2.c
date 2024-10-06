#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

float celsius_to_fahrenheit(float celsius){ //conversion calcs
    return ((9.0/5.0)*celsius+32);
}
float fahrenheit_to_celsius(float fahrenheit){
    return ((5.0/9.0)*(fahrenheit-32));
}
float celsius_to_kelvin(float celsius){
    return celsius+273.15;
}
float kelvin_to_celsius(float kelvin){
    return kelvin-273.15;
}
float fahrenheit_to_kelvin(float fahrenheit){
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
float kelvin_to_fahrenheit(float kelvin){
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
bool isCorrectInput(int user_temp,char input_scale[30],char output_scale[30]){ //check that input scales are either C, F, or, K, the user isn't converting to the same scale, and that the input temp is greater than 0 K
    if(strcmp(input_scale,"Celsius") != 0 & strcmp(input_scale,"Fahrenheit") != 0 & strcmp(input_scale,"Kelvin") != 0) {
        printf("Incorrect input scale! Reenter Values: ");
        return false;
    }
    if(strcmp(output_scale,"Celsius") != 0 & strcmp(output_scale,"Fahrenheit") != 0 & strcmp(output_scale,"Kelvin") != 0) {
        printf("Incorrect output scale! Reenter Values: ");
        return false;
    }
    if(strcmp(input_scale,output_scale) == 0){
        printf("Input cannot equal output! Reenter Values: ");
        return false;
    }
    if(strcmp(input_scale,"Kelvin") == 0 && user_temp < 0){
        printf("Input cannot be less than 0 degrees Kelvin! Reenter Values:");
        return false;
    }
    if(strcmp(input_scale,"Celsius") == 0 && user_temp < -273.15){
        printf("Input cannot be less than 0 degrees Kelvin! Reenter Values: ");
        return false;
    }
    if(strcmp(input_scale,"Fahrenheit") ==0 && user_temp < kelvin_to_fahrenheit(0)){
        printf("Input cannot be less than 0 degrees Kelvin! Reenter Values: ");
        return false;
    }
    return true;
}

void categorize_temperature(float celsius){
    if(celsius<=0){
        printf("\nTemperature Category: Freezing\nWeahter advisory: Wear a coat.");
    }
    else if(celsius<=10){
        printf("\nTemperature Category: Cold\nWeahter advisory: Wear a jacket.");
    }
    else if(celsius<=25){
        printf("\nTemperature Category: Comfortable\nWeahter advisory: Have a good day.");
    }
    else if(celsius<=35){
        printf("\nTemperature Category: Hot\nWeahter advisory: Drink lots of water.");
    }
    else if(celsius>35){
        printf("\nTemperature Category: Extreme Heat\nWeahter advisory: Stay indoors.");
    }
}

int main(){
    float user_temp;
    char input_scale[30];
    char output_scale[30];
    float output_temp;
    char reenter_values = 1;
    float temp_in_c;
    while(reenter_values == 1){
        printf("Enter the temperature value: ");
        scanf("%f", &user_temp); //program crashes if a non float is inputted
        printf("Choose the temperature scale of the input value (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%s",&input_scale); 
        printf("Choose the conversion target (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%s", &output_scale);
        if(isCorrectInput(user_temp,input_scale,output_scale)){ //calls appropriate conversion function
            if(strcmp(input_scale,"Celsius") == 0){
                temp_in_c = user_temp;
                if(strcmp(output_scale,"Fahrenheit") == 0){
                    output_temp = celsius_to_fahrenheit(user_temp);
                }
                if(strcmp(output_scale,"Kelvin") == 0){
                    
                    output_temp = celsius_to_kelvin(user_temp);
                }
            }
            else if(strcmp(input_scale,"Kelvin") == 0){
                temp_in_c = kelvin_to_celsius(user_temp);
                if(strcmp(output_scale,"Fahrenheit") == 0){
                    output_temp = kelvin_to_fahrenheit(user_temp);
                }
                if(strcmp(output_scale,"Celsius") == 0){
                    output_temp = kelvin_to_celsius(user_temp);
                }
            }
            else if(strcmp(input_scale,"Fahrenheit") == 0){
                temp_in_c = fahrenheit_to_celsius(user_temp);
                if(strcmp(output_scale,"Celsius") == 0){
                    output_temp = fahrenheit_to_celsius(user_temp);
                }
                if(strcmp(output_scale,"Kelvin") == 0){
                    output_temp = fahrenheit_to_kelvin(user_temp);
                }
            }
            printf("The temperature is %f %s",output_temp,output_scale);
            categorize_temperature(temp_in_c);
            break;
        }
        else{
            printf("(0/1): ");
            char value;
            scanf("%d", value);
            if(value == 1){
                main(); //yes, it's very bad to resursively loop this, I'm not sure why my while loop wasn't working so I'm falling back to this
            }
        }
    }
}


    