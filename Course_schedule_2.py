course_dep = dict()
course_visit = dict()
global_visit = dict()
final_out = []

def dfs_vist(course):
    # print(course)
    global course_dep
    global course_visit
    global global_visit
    global final_out
    if(course_visit[course] == 2):
        return True
    course_visit[course] = 1
    for dep in course_dep[course]:
        if(course_visit[dep] == 1):
            return False
        else:
            # course_visit[dep] = 1
            if(dfs_vist(dep)== False):
                return False;
    course_visit[course] = 2
    final_out.append(course)
    return True

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        global course_dep
        global course_visit
        global final_out
        final_out = []

        for i in range(numCourses):
            course_visit[i] = 0
            course_dep[i] = []

        for item in prerequisites:
            course_dep[item[0]].append(item[1])

        min_not_visited = 1
        cur = 0
        while(cur<numCourses):
            if(dfs_vist(cur) == False):
                return []
            while(min_not_visited<numCourses and course_visit[min_not_visited] != 0):
                min_not_visited = min_not_visited + 1
            cur = min_not_visited

        return final_out
