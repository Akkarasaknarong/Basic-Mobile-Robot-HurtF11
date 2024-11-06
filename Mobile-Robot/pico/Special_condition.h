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
  }
  if (type == "Circle") {
    // เริ่ทต้น ลงไป ขวา
    Condition_XY(0.3, -0.3);
    Condition_XY(0.6, -0.6);
    Condition_XY(0.9, -0.9);
    // ขวา ลงไป ล่าง
    Condition_XY(0.6, -1.2);
    Condition_XY(0.3, -1.5);
    Condition_XY(0.0, -1.8);
    // ล่างสุด ขึ้นไป ซ้าย
    Condition_XY(-0.3, -1.5);
    Condition_XY(-0.6, -1.2);
    Condition_XY(-0.9, -0.9);
    // ซ้าย ขึ้นไป บน
    Condition_XY(-0.6, -0.6);
    Condition_XY(-0.3, -0.3);
    Condition_XY(0.0, 0.0);
  }
}