void Special_condition(String type) {
  if (type == "Home") {
    Condition_XY(0, -1);
    Condition_XY(1, -1);
    Condition_XY(1, 0);
    Condition_XY(0, 0);
    Condition_XY(0.5, 0.5);
    Condition_XY(1, 0);
  }
  if (type == "Triangle") {
    Condition_XY(1, 0);
    Condition_XY(0.5, 0.5);
    Condition_XY(0, 0);
  }
  if (type == "Umbrella") {
    Condition_XY(-1, 0);
    Condition_XY(-0.75, 0.25);
    Condition_XY(0.75, 0.25);
    Condition_XY(1, 0);
    Condition_XY(0, 0);
    Condition_XY(0, -1);
  }
  if (type == "Star") {
    Condition_XY(0.3, 0.3);
    Condition_XY(0.6, 0);
    Condition_XY(0.9, 0);
    Condition_XY(0.6, -0.3);
    Condition_XY(0.6, -0.6);
    Condition_XY(0.3, -0.3);
    Condition_XY(0.0, -0.6);
    Condition_XY(0.0, -0.3);
    Condition_XY(-0.3, 0.0);
    Condition_XY(0, 0.0);


  }
  if (type == "Circle") {
    circle = 1;
    Condition_XY(0.3, 0);
    circle = 1;
    Condition_XY(0.6, -0.3);
    circle = 1;
    Condition_XY(0.6, -0.6);
    circle = 1;
    Condition_XY(0.3, -0.9);
    circle = 1;
    Condition_XY(0.0, -0.9);
    circle = 1;
    Condition_XY(-0.3, -0.6);
    circle = 1;
    Condition_XY(-0.3, -0.3);
    circle = 1;
    Condition_XY(0, 0);
    circle = 1;
    Condition_XY(0.2, 0);
    circle = 1;
  }
}