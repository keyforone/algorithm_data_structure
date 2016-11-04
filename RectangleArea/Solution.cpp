int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    if(E >= C || G <= A || F >= D || H <= B) return abs(A-C)*abs(B-D) + abs(E-G)*abs(F-H);

     int width1 = abs(E-C) < abs(G-A) ? abs(E-C) : abs(G-A);
     int width2 = abs(A-C) < abs(E-G) ? abs(A-C) : abs(E-G);
     int width = width1 < width2 ? width1 : width2;
     
     int height1 = abs(F-D) < abs(H-B) ? abs(F-D) : abs(H-B);
     int height2 = abs(B-D) < abs(F-H) ? abs(B-D) : abs(F-H);
     int width = height1 < height2 ? height1 : height2;

    return abs(A-C)*abs(B-D) + abs(E-G)*abs(F-H) - width*height;
}

