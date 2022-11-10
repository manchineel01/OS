#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char lastname[13];
    int group_number;
    int subjects[3];
} student;

void print_students_with_failed_subject(student students[], int students_count);
double get_percent_of_excellent_students(student students[], int students_count);
char* get_subject_with_highest_average_score(student students[], int students_count);
int get_worst_efficiency_group_number(student students[], int students_count);

void print_students_with_failed_subject(student students[], int students_count){
    int failed_students_count = 0;
    char failed_students[30][13];
    for (int i = 0; i < students_count; i++)
    {
        if (students[i].subjects[0] <= 49
         || students[i].subjects[1] <= 49
         || students[i].subjects[2] <= 49)
        {
            strcpy(failed_students[failed_students_count++], students[i].lastname);
        }
    }

    printf("\nStudents with failed subjects:\n");
    for (int i = 0; i < failed_students_count; i++)
    {
        printf("%s\n", failed_students[i]);
    }
}

double get_percent_of_excellent_students(student students[], int students_count){
    int excellent_students_count = 0;
    for (int i = 0; i < students_count; i++)
    {
        if (students[i].subjects[0] >= 80
         && students[i].subjects[1] >= 80
         && students[i].subjects[2] >= 80)
        {
            excellent_students_count++;
        }
    }
    return (double)excellent_students_count*100/(double)students_count;
}

char* get_subject_with_highest_average_score(student students[], int students_count){
    int subj_scores[3]= {0, 0, 0};
    for (int i = 0; i < students_count; i++)
    {
        subj_scores[0]+=students[i].subjects[0];
        subj_scores[1]+=students[i].subjects[1];
        subj_scores[2]+=students[i].subjects[2];
    }
    int hval = subj_scores[0];
	int position = 0;
	for(int i = 0; i < 3; i++) {
		if(hval < subj_scores[i]) {
			hval = subj_scores[i];
			position = i;
		}
	}

    if (subj_scores[0] == subj_scores[1] && subj_scores[0] == subj_scores[2])
    {
        return &"Subjects have same complexity";
    }
    if (position == 0)
    {
        return &"Web-technologies";
    }
    if (position == 1)
    {
        return &"Ukranian language";
    }
    if (position == 2)
    {
        return &"Information systems design";
    }
    
}

int get_worst_efficiency_group_number(student students[], int students_count){
    int groups_scores_sum[4] = {0, 0, 0, 0};
    for (int i = 0; i < students_count; i++)
    {
        groups_scores_sum[students[i].group_number-1] += students[i].subjects[0] + students[i].subjects[1] + students[i].subjects[2];
    }
    int sval = groups_scores_sum[0];
	int position = 0;
	for(int i = 0; i < 4; i++) {
		if(sval > groups_scores_sum[i]) {
			sval = groups_scores_sum[i];
			position = i;
		}
	}
    return position-1;
}



int main(){
    student students[30];
    int students_count;

    // enter students
    printf("Enter students count: ");
    scanf("%d", &students_count);

    for (int i = 0; i < students_count; i++)
    {
        printf("Enter student info\nLastname: ");
        scanf("%s", students[i].lastname);

        printf("Group number: ");
        scanf("%d", &students[i].group_number);
        
        printf("Subjects scores: ");
        scanf("%d %d %d", &students[i].subjects[0], &students[i].subjects[1], &students[i].subjects[2]);
    }
    
    // print students
    for (int i = 0; i < students_count; i++)
    {
        printf("\nStudent #%d\nLastname: %s\nGroup: %d, ", i+1, students[i].lastname, students[i].group_number);
        printf("Scores:\n Web-Techonlogies: %d, Ukranian language: %d, Information Systems design: %d", students[i].subjects[0], students[i].subjects[1], students[i].subjects[2]);
    }

    print_students_with_failed_subject(students, students_count);
    
    printf("\nExcellent students percent = %f", get_percent_of_excellent_students(students, students_count));

    printf("\nEasiest subject: %s ", get_subject_with_highest_average_score(students, students_count));

    printf("\nGroup number with worst efficiency: %d", get_worst_efficiency_group_number(students, students_count));
}