/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/../timer/delay.h"
#include "mcc_generated_files/pwm_hs/pwm.h"
#include "mcc_generated_files/pwm_hs/pwm_hs_interface.h"
#include "stepper.h"
#include <stdio.h>

stepper_position_t MainMove(stepper_position_t position, stepper_position_t displacement, uint16_t count_delay)
{
    //printf("\n\rInitial position:\t%.2f steps / %ld sub-steps", SUBSTEPS_TO_STEPS(position), position);
    //printf("\n\rMoving with speed:\t%.3f revolutions/second", COUNT_TO_RPS(count_delay));
    position = Stepper_Move(position, displacement, count_delay);
    //printf("\n\rFinal position: \t%.2f steps / %ld sub-steps", SUBSTEPS_TO_STEPS(position), position);
    //printf("\n\r");
    return position;
}

/*
    Main application
*/

int main(void)
{
    stepper_position_t stepper_position = 0;
    /* System initialize */
    SYSTEM_Initialize();
        
    //DELAY_milliseconds(10000);
    /*
    uint32_t desiredDutyCycle = 20000;  // Example value for 50% duty cycle //40000 100% 39984

    PWM_HS.GeneratorEnable(PWM_GENERATOR_1);    // Enable PWM generator 1
    PWM_HS.GeneratorEnable(PWM_GENERATOR_2);    // Enable PWM generator 1
    PWM_HS.GeneratorEnable(PWM_GENERATOR_3);    // Enable PWM generator 1
    PWM_HS.GeneratorEnable(PWM_GENERATOR_4);    // Enable PWM generator 1
  
    // Set the duty cycle for PWM1
    PWM_HS.DutyCycleSet(PWM_GENERATOR_1, desiredDutyCycle);
     // Set the duty cycle for PWM1
    PWM_HS.DutyCycleSet(PWM_GENERATOR_2, desiredDutyCycle);    
    // Set the duty cycle for PWM1
    PWM_HS.DutyCycleSet(PWM_GENERATOR_3, desiredDutyCycle);  
    PWM_HS.DutyCycleSet(PWM_GENERATOR_4, desiredDutyCycle);  

    
    // Trigger a software update to apply the new duty cycle
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_1);
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_2);
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_3);
     PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_4);
   
        DELAY_milliseconds(10000);
    */
    
    Stepper_Init();
    /*
    PWM_HS.DutyCycleSet(PWM_GENERATOR_1, 0xFFFF);
    PWM_HS.DutyCycleSet(PWM_GENERATOR_2, 0xFFFF);
    PWM_HS.DutyCycleSet(PWM_GENERATOR_3, 0xFFFF);
    PWM_HS.DutyCycleSet(PWM_GENERATOR_4, 0xFFFF);
    
    // Manually update the PWM trigger
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_1);
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_2);
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_3);
    PWM_HS.SoftwareUpdateRequest(PWM_GENERATOR_4);
    
    DELAY_milliseconds(10000);*/
    //printf("\n\r-----------------------------------------------");
    //printf("\n\rStepping Mode: %s, 1 step = %d sub-steps", STRING, K_MODE);
    //printf("\n\r");

    while(1)
    {
        stepper_position_t sub_steps;
        uint16_t           count_delay;

        sub_steps = STEPS_TO_SUBSTEPS(1000);        /* Positive: CW, Negative: CCW */
        //count_delay = RPS_TO_COUNT(1.0);            /* revolutions per second */

        //stepper_position = MainMove(stepper_position, sub_steps, count_delay);
                stepper_position = MainMove(stepper_position,
                                    sub_steps,
                                    1);
        
        DELAY_milliseconds(1000);
        
        sub_steps = -STEPS_TO_SUBSTEPS(2000);       /* Positive: CW, Negative: CCW */
        //count_delay = RPS_TO_COUNT(2.0);            /* revolutions per second */

        stepper_position = MainMove(stepper_position,
                                    sub_steps,
                                    1);
        DELAY_milliseconds(1000);
    } 
}