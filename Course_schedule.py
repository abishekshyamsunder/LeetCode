course_dep = dict()
course_visit = dict()
global_visit = dict()

def dfs_vist(course):
    # print(course)
    global course_dep
    global course_visit
    global global_visit
    course_visit[course] = 1
    for dep in course_dep[course]:
        if(course_visit[dep] == 1):
            return False
        else:
            # course_visit[dep] = 1
            if(dfs_vist(dep)== False):
                return False;
    course_visit[course] = 2
    return True

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        global course_dep
        global course_visit
        global global_visit

        for i in range(numCourses):
            course_visit[i] = -1
            global_visit[i] = -1
            course_dep[i] = []

        for item in prerequisites:
            course_dep[item[0]].append(item[1])

        min_not_visited = 1
        cur = 0
        course_visit[cur] = 1
        global_visit[cur] = 1

        print(course_dep)

        while(min_not_visited < numCourses):
            # print(cur,min_not_visited)
            if(cur == -1):
                cur = min_not_visited
            else:
                course_visit[cur] = 1
                if(cur == min_not_visited):
                    while(min_not_visited <= numCourses):
                        min_not_visited = min_not_visited + 1
                        if(min_not_visited == numCourses or course_visit[min_not_visited] == -1):
                            break
                if(course_dep[cur] == []):
                    course_visit[cur] = 2
                    cur = min_not_visited  
                    # course_visit = dict.fromkeys(course_visit, -1)
                # elif(course_visit[course_dep[cur]] == 1):
                #     return False
                else:
                    for d in course_dep[cur]:
                        # print(d,":",course_visit[d])
                        if(course_visit[d] == -1):
                            if(dfs_vist(d) == False):
                                return False
                        if(course_visit[d] == 1):
                            return False
                    course_visit[cur] = 2
                    cur = min_not_visited
                    # course_visit = dict.fromkeys(course_visit, -1)
                    # course_visit[cur] = 1
                    # global_visit[cur] = 1
        return True
