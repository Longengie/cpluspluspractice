#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

class Student
{
private:
    string _first_name;
    string _last_name;
    string _class_year;
    int _score;

public:
    Student (string firstName, string lastName, string classYear, int score)
    {
        _first_name = firstName;
        _last_name = lastName;
        _class_year = classYear;
        _score = score;
    }

    int getClassYear ()
    {
        if (_class_year == "Freshman")
            return 1;
        if (_class_year == "Sophomore")
            return 2;
        if (_class_year == "Junior")
            return 3;
        if (_class_year == "Senior")
            return 4;
        
        return 0;
    }

    int getScore ()
    {
        return _score;
    }
};

class CalculateStudent
{
private:
    int _lowest_score = -1, _highest_score = -1,
        _total_score = 0, _total_student = 0,
        _freshman = 0, _score_freshman = 0,
        _sophomore = 0, _score_sophomore = 0,
        _junior = 0, _score_junior = 0,
        _senior = 0, _score_senior = 0;

    vector<tuple<int, int, string>> _error_list;

    void countClassYear(Student student)
    {
        int class_year = student.getClassYear();
        int score = student.getScore();

        switch (class_year)
        {
        case 1:
            _freshman += 1;
            _score_freshman += score;
            return;
        
        case 2:
            _sophomore += 1;
            _score_sophomore += score;
            return;

        case 3:
            _junior += 1;
            _score_junior += score;
            return;

        case 4:
            _senior += 1;
            _score_senior += score;
            return;
        }

        throw 100;
    }

    void getScoreRank (Student student)
    {
        int score = student.getScore();

        if (score < 0)
            throw 200;

        _total_score += score;

        if (_highest_score == -1 || score > _highest_score)
            _highest_score = score;
        
        if (_lowest_score == -1 || score < _lowest_score)
            _lowest_score = score;
    }

    Student inputStudent (string line)
    {
        string first_name, last_name, class_year, word;
        stringstream line_stream(line);
        int score;
        int input = 1;
        

        while (getline(line_stream, word, ' '))
        {
            switch (input)
            {
            case 1:
                first_name = word;
                break;

            case 2:
                last_name = word;
                break;

            case 3:
                class_year = word;
                break;

            case 4:
                try
                {
                    score = stoi(word);
                }
                catch(const std::exception&)
                {
                    throw 300;
                }
                break;
            
            default:
                break;
            }

            input++;
        }
        
        return Student(first_name, last_name, class_year, score);
    }

    void displayScore ()
    {
        cout << "The number of freshman is " << _freshman << endl;
        cout << "The number of sophomore is " << _sophomore << endl;
        cout << "The number of junior is " << _junior << endl;
        cout << "The number of senior is " << _senior << endl;
        cout << "The total number of students is " << _total_student << endl;
        cout << "The sum of freshman scores is " << _score_freshman << endl;
        cout << "The sum of sophomore scores is " << _score_sophomore << endl;
        cout << "The sum of  of junior scores is " << _score_junior << endl;
        cout << "The sum of senior scores is " << _score_senior << endl;
        cout << "The highest score of all students is " << (_highest_score == -1 ? 0 : _highest_score) << endl;
        cout << "The lowest score of all students is " << (_lowest_score == -1 ? 0 : _lowest_score) << endl;
        cout << "The average of all scores is ";
        cout << fixed << showpoint << setprecision(2) << (double) _total_score / _total_student << endl;
    }

    void getErrorLabel(int error_code)
    {
        switch (error_code)
        {
        case 100:
            cout << "Class Year Error" << endl;
            break;
        case 200:
            cout << "Score Error" << endl;
            break;
        case 300:
            cout << "Score Entry Error" << endl;
            break;
        case 400:
            cout << "File read error" << endl;
        default:
            cout << "The Program meet unexpected Error" << endl;
            break;
        }
        cout << "The Program will stop now" << endl;
    }

    void readFile ()
    {
        ifstream inFile;
        string line;
        int index = 0;

        try
        {
            inFile.open("students.txt");
        }
        catch(const std::exception&)
        {
            _error_list.push_back(make_tuple(index, 500, line));
            return;
        }
        
        

        while (getline(inFile, line)) // Suppose to use eof but I designed to work different
        {
            index ++;

            try
            {
                Student student = inputStudent(line);

                countClassYear(student);
                getScoreRank(student);
            }
            catch(int error)
            {
                _error_list.push_back(make_tuple(index, error, line));
                continue;
            }

            _total_student ++;
        }
        
        displayScore ();
    }
public:
    int mainProgress()
    {
        readFile();
        if (!_error_list.empty())
        {
            for (tuple<int, int, string> error_entry : _error_list)
            {
                cout << "Student " << get<0>(error_entry) << " error: " << endl;
                getErrorLabel(get<1>(error_entry));
                cout << "Data: " << endl << get<2>(error_entry) << endl;
            }
            
            return 0;
        }
        return 1;
    }
};

int main ()
{
    CalculateStudent calculate;
    return calculate.mainProgress();
}