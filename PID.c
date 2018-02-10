typedef enum {false, true} bool;
#define abs(x) ((x) < 0 ? -(x) : (x))

double Kp = 1;
double Ki = 1;
double Kd = 1;

double Perror = 0;
double Ierror = 0;
double Derror = 0;
double Ierror_abs = 0;

int counter = 0;
bool needsTraining = true;
double currentError = 0;
double previousError = 0;
double cumulativeError = 0;
const int epochLength = 200;

const double errorThreshold = 0.005;
const double learnRate = 0.01;

void updateError(double error){
    Ierror_abs = abs(error);
    cumulativeError += (error * error);
}

void resetError(){
    Ierror_abs = 0;
    cumulativeError = 0;
}

void evaluatePID(){
    if(!needsTraining) return;
        currentError = sqrt(cumulativeError / epochLength);
        needsTraining = (currentError > errorThreshold);
}