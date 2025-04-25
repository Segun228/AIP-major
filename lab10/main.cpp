#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student{
    private: 
        struct full_name_template{
            string first_name;
            string second_name;
            string fathers_name;
        };
        struct grades_template{
            vector <double> grades_data;
            double average;
        };

        int group;
        full_name_template full_name;
        grades_template grades;

    public:
    Student(string firstname_input, string secondname_input, string fathername_input, int group_input, vector <int> grades_input){
        std::cout << "Инициализация студента..." << endl;
        full_name.first_name = firstname_input;
        full_name.second_name = secondname_input;
        full_name.fathers_name = fathername_input;
        group = group_input;
        std::cout << full_name.first_name << " " << full_name.second_name << " " << full_name.fathers_name << endl;
        std::cout << "Группа " << group << endl;
        std::cout << "Оценки: " << endl;
        for(auto i = 0; i < 5; i++){
            grades.grades_data.push_back(grades_input[i]);
            std::cout << grades.grades_data[i]  << "\t";
        }
        std::cout << endl;
        this->recount_average();
        std::cout << "Средний балл: " << this->grades.average << endl;
        std::cout << endl;
        std::cout << endl;
    }


    vector <string> setFullName(vector <string> newName){
        full_name.first_name = newName[0];
        full_name.second_name = newName[1];
        full_name.fathers_name = newName[2];
        std::cout << full_name.first_name << " " << full_name.second_name << " " << full_name.fathers_name << endl;
        return newName;
    }


    vector <string> getFullName(){
        return {full_name.first_name, full_name.second_name, full_name.fathers_name};
    }


    int setGroup(int newGroup){
        group = newGroup;
        return group;
    }


    int getGroup(){
        return group;
    }


    vector <double> getGrades(){
        return grades.grades_data;
    }


    vector <double> addGrade(int newGrade){
        grades.grades_data.push_back(newGrade);
        std::cout << "Обновленные оценки" << endl;
        for(auto el : grades.grades_data){
            std::cout << el << "\t";
        }
        return grades.grades_data;
    }

    vector <double> deleteGrade(int index){
        std::cout << "удаленная оценка" << grades.grades_data[index] <<endl;
        grades.grades_data[index] = 0;
        return grades.grades_data;
    }

    double recount_average(){
        double sum_grades = 0;
        for(auto el : grades.grades_data){
            sum_grades+=el;
        }
        grades.average = sum_grades / grades.grades_data.size();
        return grades.average;
    }

    double get_average(){
        return grades.average;
    }

    void print_student(){
        std::cout << endl;
        std::cout << endl;
        std::cout << "Информация:" << endl;
        std::cout << full_name.first_name << " " << full_name.second_name << " " << full_name.fathers_name << endl;
        std::cout << "Группа " << group << endl;
        std::cout << "Оценки: " << endl;
        for(auto i = 0; i < 5; i++){
            std::cout << grades.grades_data[i]  << "\t";
        }
        std::cout << endl;
        this->recount_average();
        std::cout << "Средний балл: " << this->grades.average << endl;
        std::cout << endl;
        std::cout << endl;
    }
};



struct Node{
    Node* next;
    Student* student_field;
};



double calculate_average(Node* head){
    double summ = 0;
    int counter = 0;
    if(head == nullptr){
        cout << "Переданный список пуст";
        return 0;
    }
    while(head!=nullptr){
        summ+=head->student_field->get_average();
        counter++;
        head = head->next;
    }
    cout << "Средний балл для всего списка составляет:"<< (summ/counter) <<endl;
    cout << endl;
    return (summ/counter);
}

Node* delete_below_average(Node* head, double average){
    if(head == nullptr){
        cout << "Переданный список пуст";
        return nullptr;
    }
    Node* current = head;
    Node* last_visited = head;
    while(current!=nullptr){
        if(current->student_field->get_average() >= average){
            last_visited = current;
            current = current->next;
        }
        else{
            if(head==current){
                Node* del = current;
                last_visited = current->next;
                current = current->next;
                head = head->next;
                delete del->student_field;
                delete del;
            }
            else{
                Node* del = current;
                last_visited->next = current->next;
                current = current->next;
                delete del->student_field;
                delete del;
            }
            
        }
    }
    return head;
}



int main(){
    cout << "Лаба 10" << endl;
    string input_file_name;
    string output_file_name;
    cout << "введите имя входного файла" << endl;
    cin.clear();
    cin >> input_file_name;
    cout << "введите имя выходного файла" << endl;
    cin.clear();
    cin >> output_file_name;
    

    Node* head = nullptr;// первый нулевой элемент списка


    ifstream fin(input_file_name);
    do{
        if (!fin.is_open()){
            cout << "Файл не найден, повторите попытку" << endl;
            cout << "введите имя входного файла" << endl;
            cin >> input_file_name;
        }
    }while(!fin.is_open());
    


    ofstream fout(output_file_name);
    do{
        if (!fout.is_open()){
            cout << "Файл не найден, повторите попытку" << endl;
            cout << "введите имя выходного файла" << endl;
            cin >> output_file_name;
        }
    }while(!fout.is_open());
    

    string firstname_input;
    string secondname_input;
    string fathername_input; 
    int group_input; 
    int buf;
    vector <int> grades_input;
    while(getline(fin, firstname_input)){
        getline(fin, secondname_input);
        getline(fin, fathername_input);
        fin >> group_input;
        fin.ignore();
        grades_input.clear();
        for(int i = 0; i<5; i++){
            fin >> buf;
            grades_input.push_back(buf);
        }
        fin.ignore();
        Node* new_node = new Node;
        new_node->next = head;
        head = new_node;
        new_node->student_field = new Student(firstname_input, secondname_input, fathername_input, group_input, grades_input);
    }
    double av = calculate_average(head);
    head = delete_below_average(head, av);

    cout << "Список изменен, выводим в файл" << endl;

    while(head!=nullptr){
        head->student_field->print_student();
        fout << endl;
        fout << endl;
        fout << head->student_field->getFullName()[0]<< " " << head->student_field->getFullName()[1] << " " << head->student_field->getFullName()[2] << endl;
        fout << "Группа " << head->student_field->getGroup() << endl;
        fout << "Оценки: " << endl;
        for(auto i = 0; i < 5; i++){
            fout << head->student_field->getGrades()[i]  << "\t";
        }
        fout << endl;
        head->student_field->recount_average();
        fout << "Средний балл: " << head->student_field->get_average() << endl;
        fout << endl;
        fout << endl;
        head = head->next;
    }

    fin.close();
    fout.close();
    return 0;
}