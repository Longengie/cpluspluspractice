#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class GetScore
{
    private:
        int inputScore() {
            int score;
            cin >> score;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(200,'\n');
                throw 100;
            }
            
            return score;
        }
        bool checkScoreValid(int score)
        {
            if ((score < 0) || (score > 100))
            {
                return false;
            }
            return true;
        }

        void checkThreeScoreValid(int exam1, int exam2, int exam3)
        {
            if(!checkScoreValid(exam1))
            {
                throw 101;
            }
            if(!checkScoreValid(exam2))
            {
                throw 102;
            }
            if(!checkScoreValid(exam3))
            {
                throw 103;
            }
        }

        double getWeightedExam(int exam1, int exam2, int exam3)
        {
            double weighted_total = (double) exam1 * 0.25
            + (double) exam2 * 0.35 +
            (double) exam3 * 0.4;
            return weighted_total;
        }

        double getExtraPoints(double weighted)
        {
            double extra = weighted * 0.05;
            return extra;
        }

        double getFinalScore(double weighted, double extra)
        {
            return weighted + extra;
        }

        void printScore(int exam1, int exam2, int exam3,
        double extra,
        double final)
        {
            cout << "Exam 1 Score: " << fixed << showpoint << setprecision(2) << exam1<< endl;
            cout << "Exam 2 Score: " << fixed << showpoint << setprecision(2) << exam2 << endl;
            cout << "Exam 3 Score: " << fixed << showpoint << setprecision(2) << exam3 << endl;
            cout << "Extra Points: " << fixed << showpoint << setprecision(2) << extra << endl;
            cout << "Final Score: " << fixed << showpoint << setprecision(2) << extra << endl;
        }

        void exportScore(int exam1, int exam2, int exam3,
        double extra,
        double final)
        {
            ofstream outData;
            outData.open("lab1exam.txt");
            outData << "Exam 1 Score: " << fixed << showpoint << setprecision(2) << exam1<< endl;
            outData << "Exam 2 Score: " << fixed << showpoint << setprecision(2) << exam2 << endl;
            outData << "Exam 3 Score: " << fixed << showpoint << setprecision(2) << exam3 << endl;
            outData << "Extra Points: " << fixed << showpoint << setprecision(2) << extra << endl;
            outData << "Final Score: " << fixed << showpoint << setprecision(2) << extra << endl;
            outData.close();
        }
        void printExportScore(int exam1, int exam2, int exam3,
        double extra,
        double final)
        {
            printScore(exam1, exam2, exam3, extra, final);
            exportScore(exam1, exam2, exam3, extra, final);
        }
    public:
        int mainProcess()
        {
            int exam1_score, exam2_score, exam3_score;
            try
            {
                cout << "Enter exam 1 Score:";
                exam1_score = inputScore();
                cout << "Enter exam 2 Score:";
                exam2_score = inputScore();
                cout << "Enter exam 3 Score:";
                exam3_score = inputScore();
                checkThreeScoreValid(exam1_score, exam2_score, exam3_score);
            }
            catch(int error)
            {
                switch(error)
                {
                    case 100:
                        cout << "Meet input error. Will exit" << endl;
                    case 101:
                        cout << "Exam 1 input error. Will exit" << endl;
                    break;
                    case 102:
                        cout << "Exam 2 input error. Will exit" << endl;
                    break;
                    case 103:
                        cout << "Exam 3 input error. Will exit" << endl;
                    break;
                }
                return 2;
            }
            double weighted_total = getWeightedExam(exam1_score, exam2_score, exam3_score);
            double extra_points = getExtraPoints(weighted_total);
            double final_score = getFinalScore(weighted_total, extra_points);
            printExportScore(exam1_score,exam2_score,exam3_score, extra_points, final_score);
            return 1;
        }

};

int main()
{
    GetScore getScore;
    int result = getScore.mainProcess();
    if (result != 1)
    {
        return 0;
    }
    return 1;
}