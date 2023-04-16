#pragma once

#include "../globals.hpp"
#include "../lib/autonomous.hpp"

namespace route {
    // SUBROUTES

    inline void spin_roller() {
        auton::set_intake(-INTK_RPM);
        auton::advance_time(-WHEEL_RPM*0.3, 0.5);
        auton::set_intake(0);
    }

    inline void get_disks() {
        // turn to intake other 3 disk
        auton::turn_to(225);
        //move towards other 3 disks
        auton::set_intake(200);
        auton::advance_time(-WHEEL_RPM, 2.53);
        auton::advance_time(WHEEL_RPM, 0.5);

        auton::turn_to(135);
        auton::shoot(BLU_RPM*0.9, 0.95, 5, 3);
    }

    // ROUTES

    inline void close_hi() {
        #if DRV_MODE == TANK_DRV
        auton::set_flywheel(BLU_RPM); // pre-accelerate
        // spin roller
        spin_roller();
        // set up shoot
        auton::turn_to(90);
        // shoot
        auton::shoot(BLU_RPM*0.9, 0.95, 5, 2);
        #elif DRV_MODE == X_DRV
        #endif  
    }

    inline void far_hi() {
        #if DRV_MODE == TANK_DRV
        auton::set_flywheel(BLU_RPM); // pre-accelerate
        // go to roller
        auton::advance_time(-WHEEL_RPM, TILE/WHEEL_LSPD);
        auton::turn_to(90);
        // spin roller
        spin_roller();
        // set up shoot
        auton::advance_time(WHEEL_RPM, TILE*0.5/WHEEL_LSPD);
        // shoot
        auton::shoot(BLU_RPM*0.9, 0.95, 5, 2);
        get_disks();
        #elif DRV_MODE == X_DRV
        #endif
    }

    inline void close_lo() { // incomplete
        #if DRV_MODE == TANK_DRV
        auton::set_flywheel(BLU_RPM); // pre-accelerate
        spin_roller();
        #elif DRV_MODE == X_DRV
        #endif
    }

    inline void far_lo() {
        #if DRV_MODE == TANK_DRV
        auton::set_flywheel(BLU_RPM); // pre-accelerate
        // go to roller
        auton::advance_time(-WHEEL_RPM, TILE/WHEEL_LSPD);
        auton::turn_to(90);
        // spin roller
        spin_roller();
        // set up shoot
        auton::turn_to(0);
        auton::advance_time(WHEEL_RPM, TILE*0.5/WHEEL_LSPD);
        // shoot
        auton::shoot(BLU_RPM*0.9, 0.95, 5, 2);
        get_disks();
        #elif DRV_MODE == X_DRV
        #endif
    }

    inline void test() {
        auton::shoot(BLU_RPM*0.8, 0.95, 5, 2);
    }

    // SKILLS ROUTE

    inline void skills() {
        
    }
}