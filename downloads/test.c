    // 绘制矩形
    int rectX = 50;
    int rectY = 50;
    int rectWidth = 100;
    int rectHeight = 50;

    gdImageRectangle(image, rectX, rectY, rectX + rectWidth, rectY + rectHeight, whiteColor);

    // 旋转角度（以弧度为单位）
    double rotationAngle = 45.0;
    double rotationRad = rotationAngle * (M_PI / 180.0);

    // 旋转矩形
    int rotatedX = static_cast<int>(rectX * cos(rotationRad) - rectY * sin(rotationRad));
    int rotatedY = static_cast<int>(rectX * sin(rotationRad) + rectY * cos(rotationRad));

    gdImageRectangle(image, rotatedX, rotatedY, rotatedX + rectWidth, rotatedY + rectHeight, whiteColor);