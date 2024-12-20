void Two_motor_FR(String direction, float distance) {
  encoder_FL.reset();
  encoder_BR.reset();
  average_encoder = 0;
  average_delta = 0;
  en_FL = 0;
  en_FR = 0;
  en_BL = 0;
  en_BR = 0;
  integral_FR = 0;
  integral_FL = 0;
  integral_BL = 0;
  integral_BR = 0;
  previous_error_FL = 0;
  previous_error_FR = 0;
  previous_error_BL = 0;
  previous_error_BR = 0;
  error_FL = 0;
  error_FR = 0;
  error_BL = 0;
  error_BR = 0;
  output_FL = 0;
  output_FR = 0;
  output_BL = 0;
  output_BR = 0;
  delta_FL = 0;
  delta_FR = 0;
  delta_BL = 0;
  delta_BR = 0;
  cal_delta_FL = 0;
  cal_delta_FR = 0;
  cal_delta_BL = 0;
  cal_delta_BR = 0;
  
  tick = distance * (370) * 100;
  average_encoder = 0;
  while (average_encoder < tick) {
    en_FL = encoder_FL.getCount();
    en_BR = encoder_BR.getCount();
    average_encoder = (abs(en_FL) + abs(en_BR)) / 2;

    if (key_overencoder == 0) {
      en_FL -= over_encoder_FL;
      en_FR -= over_encoder_FR;
      en_BL -= over_encoder_BL;
      en_BR -= over_encoder_BR;
      key_overencoder = 1;
    }

    delta_FL = tick - abs(en_FL);
    delta_BR = tick - abs(en_BR);

    average_delta = (abs(delta_FL) + abs(delta_BR)) / 2;

    if (delta_FL > average_delta) {
      cal_delta_FL = delta_FL - average_delta;
      if (cal_delta_FL < Error_Phase_1) {
        error_FL = 0;
      }
      if (cal_delta_FL > Error_Phase_1) {
        error_FL = 1;
      }
      if (cal_delta_FL > Error_Phase_2) {
        error_FL = 3;
      }
      if (cal_delta_FL > 200) {
        error_FL = 4;
      }
      if (cal_delta_FL > 500) {
        error_FL = 5;
      }
      if (cal_delta_FL > 1000) {
        error_FL = 7;
      }
    }

    if (delta_FL < average_delta) {
      cal_delta_FL = average_delta - delta_FL;
      if (cal_delta_FL < Error_Phase_1) {
        error_FL = 0;
      }
      if (cal_delta_FL > Error_Phase_1) {
        error_FL = -1;
      }
      if (cal_delta_FL > Error_Phase_2) {
        error_FL = -3;
      }
      if (cal_delta_FL > 200) {
        error_FL = -4;
      }
      if (cal_delta_FL > 500) {
        error_FL = -5;
      }
      if (cal_delta_FL > 1000) {
        error_FL = -7;
      }
    }

    // Cal delta for BR
    if (delta_BR > average_delta) {
      cal_delta_BR = delta_BR - average_delta;
      if (cal_delta_BR < Error_Phase_1) {
        error_BR = 0;
      }
      if (cal_delta_BR > Error_Phase_1) {
        error_BR = 1;
      }
      if (cal_delta_BR > Error_Phase_2) {
        error_BR = 2;
      }
      if (cal_delta_BR > 200) {
        error_BR = 3;
      }
      if (cal_delta_BR > 500) {
        error_BR = 5;
      }
      if (cal_delta_BR > 1000) {
        error_BR = 7;
      }
    }

    if (delta_BR < average_delta) {
      cal_delta_BR = average_delta - delta_BR;
      if (cal_delta_BR < Error_Phase_1) {
        error_BR = 0;
      }
      if (cal_delta_BR > Error_Phase_1) {
        error_BR = -1;
      }
      if (cal_delta_BR > Error_Phase_2) {
        error_BR = -2;
      }
      if (cal_delta_BR > 200) {
        error_BR = -3;
      }
      if (cal_delta_BR > 500) {
        error_BR = -5;
      }
      if (cal_delta_BR > 1000) {
        error_BR = -7;
      }
    }

    output_FL = (Kp_FL * error_FL) + (Ki_FL * integral_FL) + (Kd_FL * (error_FL - previous_error_FL));
    output_FL = constrain(output_FL, -255, 255);
    output_BR = (Kp_BR * error_BR) + (Ki_BR * integral_BR) + (Kd_BR * (error_BR - previous_error_FL));
    output_BR = constrain(output_BR, -255, 255);

    if (direction == "FR") {
      motor_FL.speed((base_speed + output_FL) * 1);
      motor_BR.speed((base_speed + output_BR) * 1);
    } else if (direction == "BL") {
      motor_FL.speed((base_speed + output_FL) * -1);
      motor_BR.speed((base_speed + output_BR) * -1);
    }

    integral_FL += error_FL;
    previous_error_FL = error_FL;
    integral_BR += error_BR;
    previous_error_BR = error_BR;

    // Velocity -----------------------------------------------------------------------
    if ((millis()) - previousTime_velocity >= DELTA_T * 1000) {
      ticksChange_velocity = average_encoder - previousTicks_velocity;
      omega = (ticksChange_velocity / (float)TICKS_PER_REVOLUTION) * 2 * PI / DELTA_T;
      velocity = omega * WHEEL_RADIUS;
      previousTime_velocity = millis();
      previousTicks_velocity = average_encoder;
    }
    // Velocity -----------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------------------------
    if (direction == "FR") {
      Serial.print("Current Position (X,Y) = (");
      Serial.print((position_x + int(average_encoder / 370)) / 100);
      Serial.print(" m, ");
      Serial.print((position_y + int(average_encoder / 370)) / 100);
      Serial.print(" m)");
      Serial.print("          ");
    } else if (direction == "BL") {
      Serial.print("Current Position (X,Y) = (");
      Serial.print((position_x - int(average_encoder / 370)) / 100);
      Serial.print(" m, ");
      Serial.print((position_y - int(average_encoder / 370)) / 100);
      Serial.print(" m)");
      Serial.print("          ");
    }
    // ----------------------------------------------------------------------------------------------------------------------------------
    Serial.print("Velocity = ");
    Serial.print(velocity);
    Serial.print(" m/s");
    Serial.print("          ");

    // Serial.print("tick = ");
    // Serial.print(tick);
    // Serial.print("          ");

    // Serial.print("average_encoder = ");
    // Serial.print(average_encoder);
    // Serial.print("          x          ");

    // Serial.print("error_FL = ");
    // Serial.print(delta_FL - average_delta);
    // Serial.print("          ");

    // Serial.print("error_BR = ");
    // Serial.print(delta_BR - average_delta);
    // Serial.print("          x          ");

    // Serial.print("encoder FL = ");
    // Serial.print(en_FL);
    // Serial.print("          ");

    // Serial.print("encoder BR = ");
    // Serial.print(en_BR);
    // Serial.print("          ");

    // Serial.print("average_delta = ");
    // Serial.print(average_delta);
    // Serial.print("          ");

    // Serial.print("delta_FL = ");
    // Serial.print(delta_FL);
    // Serial.print("          ");

    // Serial.print("delta_BR = ");
    // Serial.print(delta_BR);

    // Serial.print("          x          ");

    // Serial.print("output_FL = ");
    // Serial.print(base_speed + output_FL);
    // Serial.print("          ");

    // Serial.print("output_BR = ");
    // Serial.print(base_speed + output_BR);
    // Serial.print("          ");

    Serial.print("\n");
  }
  distance = 0;
  if (direction == "FR") {
    position_x += average_encoder / 370;
    position_y += average_encoder / 370;
  } else if (direction == "BL") {
    position_x -= average_encoder / 370;
    position_y -= average_encoder / 370;
  }
  over_encoder_FR = tick - abs(en_FR);
  over_encoder_FL = tick - abs(en_FL);
  over_encoder_BR = tick - abs(en_BR);
  over_encoder_BL = tick - abs(en_BL);
  key_overencoder = 0;
}
