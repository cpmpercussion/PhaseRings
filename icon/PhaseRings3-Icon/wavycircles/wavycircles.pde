


void setup() {
  size(1200,1200);
  background(255);
  smooth();

  float radius = 60;
  for (int i = 0; i < 6; i++) {
    float freq = int(random(0, 50));
    float amp = random(min(radius * 0.2, 50));

    if (i == 3) freq =0;
    if (i == 5) freq = 0;

    drawWavyCircle(radius, freq, amp);
    radius += 100;
  }
}

void draw() {
}

void drawWavyCircle(float r, float f, float a) {
  stroke(0);
  strokeWeight(4);
  strokeCap(ROUND);

  float radius = r;
  float points = 5000;

  float waveScale = a;
  float waveFreq = f;

  int cX = width/2;
  int cY = height/2;

  float oldX = radius;
  float oldY = 0;

  float h1scale = random(0.5);
  float h2scale = random(0.5);
  float h3scale = random(0.5);
  float h4scale = random(0.5);
  
//  println(h1scale + " " + h2scale + " " + h3scale + " " + h4scale);

  for (int i = 0; i <= points; i++) {
    float theta = i * TWO_PI / points;
    float shift = waveScale * sin(waveFreq * theta);

//    shift += h1scale * waveScale * sin(waveFreq*2*theta);
//    shift += h2scale * waveScale * sin(waveFreq*3*theta);
//    shift += h3scale * waveScale * sin(waveFreq*4*theta);
//    shift += h4scale * waveScale * sin(waveFreq*5*theta);

    float x = (radius + shift) * cos(theta);
    float y = (radius + shift) * sin(theta);
    line(oldX+cX, oldY+cY, x+cX, y+cY);
    oldX = x;
    oldY = y;
  }
}

void mouseClicked( ) {
  saveFrame();
}
