#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    float ax, ay, aAngle = -15;
    float bx, by, bAngle = 30;
    float incDec = 15;
    float dotproduct = 0;
    float crossproduct = 0;
    float dx, dy;
    float cx, cy;
    float angleBetween;
    while (notQuit) {
        clear(0, 40, 0);
        mathAxis(1.5f, 200);
        if (isTrigger(KEY_D)) {
            bAngle += -incDec;
        }
        if (isTrigger(KEY_A)) {
            bAngle += incDec;
        }
        //vectorA
        ax = cos(aAngle);
        ay = sin(aAngle);
        stroke(244);
        strokeWeight(10);
        mathArrow(0, 0, ax, ay);
        //vectorB
        bx = cos(bAngle);
        by = sin(bAngle);
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        stroke(100);
        strokeWeight(10);
        mathArrow(0, 0, bx, by);
        //内積・外積・なす角計算
        dotproduct = ax * bx + ay * by;
        crossproduct = ax * by - ay * bx;
        angleBetween = atan2(crossproduct, dotproduct);
        //内積cos表示
        stroke(200,200,255);
        strokeWeight(10);
        cx = ax * dotproduct;
        cy = ay * dotproduct;
        mathLine(0, 0, cx, cy);
        //外積sin表示
        stroke(255, 200, 200);
        strokeWeight(10);
        dx = -ay * crossproduct;
        dy = ax * crossproduct;
        mathLine(cx, cy, dx+cx, dy+cy);
        //aAngleからのなす角表示
        stroke(200, 255, 255);
        mathArc(aAngle,angleBetween,0.1f);

        textSize(50);
        text((let)"dotproduct:ax*bx+ay*by= " + dotproduct,0,50);
        text((let)"crossproduct:ax*by-ay*bx= " + crossproduct, 0, 100);
        text((let)"angleBetween:atan2(cross,dot)= " + round(angleBetween), 0, 150);
    }
}
/*
#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    //ベクトルａ，ｂ
    float ax, ay, aAngle = -15;
    float bx, by, bAngle = 30;
    //角度増減値
    float incDec = 15;
    //内積、外積、なす角
    float dotProduct = 0;
    float crossProduct = 0;
    float angleBetween = 0;
    while (notQuit) {
        clear(0, 40, 0);
        mathAxis(1.5f, 200);
        //ベクトルａの回転
        if (isTrigger(KEY_A))aAngle += incDec;
        if (isTrigger(KEY_D))aAngle += -incDec;
        ax = cos(aAngle);
        ay = sin(aAngle);
        //ベクトルｂの回転
        if (isTrigger(KEY_LEFT))bAngle += incDec;
        if (isTrigger(KEY_RIGHT))bAngle += -incDec;
        bx = cos(bAngle);
        by = sin(bAngle);
        //ベクトルｂをマウス位置にする
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        //内積
        dotProduct = ax * bx + ay * by;
        //外積
        crossProduct = ax * by - ay * bx;
        //なす角
        angleBetween = atan2(crossProduct, dotProduct);
        //ベクトルａがｂを追いかける
        if (isPress(KEY_Z)) { aAngle += angleBetween * 0.1f; }
        //ベクトルｂ描画
        strokeWeight(10);
        textSize(50);
        stroke(180);
        mathArrow(0, 0, bx, by);
        fill(180);
        mathText("b", bx, by);
        //ベクトルａ描画
        stroke(250);
        mathArrow(0, 0, ax, ay);
        fill(250);
        mathText("a", ax, ay);
        //底辺描画
        float cx = ax * dotProduct;
        float cy = ay * dotProduct;
        strokeWeight(10);
        stroke(150, 190, 255);
        mathLine(0, 0, cx, cy);
        //高さ描画（ベクトルａを９０°回転させ、外積を掛ける）
        float dx = -ay * crossProduct;
        float dy = ax * crossProduct;
        stroke(255, 190, 190);
        mathLine(cx, cy, cx + dx, cy + dy);

        //式と値テキスト描画
        textSize(50);
        fill(150, 190, 255);
        text((let)"dot:   ax * bx + ay * by = " + dotProduct, 0, 50);
        fill(255, 190, 190);
        text((let)"cross: ax * by - ay * bx = " + crossProduct, 0, 100);
        //なす角テキスト描画
        stroke(255, 255, 200);
        mathArc(aAngle, angleBetween, 0.1f);
        textSize(50);
        fill(255, 255, 200);
        text((let)"atan2(cross,dot) = " + round(angleBetween), 0, 150);
    }
}
*/