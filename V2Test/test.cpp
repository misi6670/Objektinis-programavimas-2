#include "pch.h"
#include "../V2.0/studentas.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StudentasTest, countVidurkis) {
    vector <int> nd;
    int n = 5;
    nd.push_back(5);
    nd.push_back(9);
    nd.push_back(6);
    nd.push_back(3);
    nd.push_back(7);
    Studentas stud(0, "", "", n, nd, 0);
    ASSERT_EQ((float)6, (float)stud.countVidurkis());
    
    vector <int> nd1;
    int n1 = 10;
    nd1.push_back(1);
    nd1.push_back(10);
    nd1.push_back(2);
    nd1.push_back(3);
    nd1.push_back(5);
    nd1.push_back(4);
    nd1.push_back(2);
    nd1.push_back(5);
    nd1.push_back(3);
    nd1.push_back(1);
    Studentas stud1(0, "", "", n1, nd1, 0);
    ASSERT_EQ((float)3.6, (float)stud1.countVidurkis());
    
    vector <int> nd2;
    int n2 = 7;
    nd2.push_back(10);
    nd2.push_back(9);
    nd2.push_back(6);
    nd2.push_back(6);
    nd2.push_back(10);
    nd2.push_back(7);
    nd2.push_back(8);
    Studentas stud2(0, "", "", n2, nd2, 0);
    ASSERT_EQ((float)8, (float)stud2.countVidurkis());
}

TEST(StudentasTest, countMediana) {
    vector <int> nd;
    int n = 5;
    nd.push_back(5);
    nd.push_back(9);
    nd.push_back(6);
    nd.push_back(3);
    nd.push_back(7);
    Studentas stud(1, "", "", n, nd, 0);
    ASSERT_EQ((float)6, (float)stud.countMediana());

    vector <int> nd1;
    int n1 = 10;
    nd1.push_back(1);
    nd1.push_back(10);
    nd1.push_back(2);
    nd1.push_back(3);
    nd1.push_back(5);
    nd1.push_back(4);
    nd1.push_back(2);
    nd1.push_back(5);
    nd1.push_back(3);
    nd1.push_back(1);
    Studentas stud1(1, "", "", n1, nd1, 0);
    ASSERT_EQ((float)3, (float)stud1.countMediana());

    vector <int> nd2;
    int n2 = 8;
    nd2.push_back(10);
    nd2.push_back(9);
    nd2.push_back(6);
    nd2.push_back(6);
    nd2.push_back(10);
    nd2.push_back(7);
    nd2.push_back(8);
    nd2.push_back(7);
    Studentas stud2(1, "", "", n2, nd2, 0);
    ASSERT_EQ((float)7.5, (float)stud2.countMediana());
}

TEST(StudentasTest, GalutinisBalasVidurkis) {
    vector <int> nd;
    int n = 5;
    nd.push_back(5);
    nd.push_back(9);
    nd.push_back(6);
    nd.push_back(3);
    nd.push_back(7);
    Studentas stud(0, "", "", n, nd, 8);
    ASSERT_EQ((float)7.2, (float)stud.getGalutinis());
    
    vector <int> nd1;
    int n1 = 10;
    nd1.push_back(1);
    nd1.push_back(10);
    nd1.push_back(2);
    nd1.push_back(3);
    nd1.push_back(5);
    nd1.push_back(4);
    nd1.push_back(2);
    nd1.push_back(5);
    nd1.push_back(3);
    nd1.push_back(1);
    Studentas stud1(0, "", "", n1, nd1, 5);
    ASSERT_EQ((float)4.44, (float)stud1.getGalutinis());
    
    vector <int> nd2;
    int n2 = 7;
    nd2.push_back(10);
    nd2.push_back(9);
    nd2.push_back(6);
    nd2.push_back(6);
    nd2.push_back(10);
    nd2.push_back(7);
    nd2.push_back(8);
    Studentas stud2(0, "", "", n2, nd2, 5);
    ASSERT_EQ((float)6.2, (float)stud2.getGalutinis());
}

TEST(StudentasTest, GalutinisBalasMediana) {
    vector <int> nd;
    int n = 5;
    nd.push_back(5);
    nd.push_back(9);
    nd.push_back(6);
    nd.push_back(3);
    nd.push_back(7);
    Studentas stud(1, "", "", n, nd, 8);
    ASSERT_EQ((float)7.2, (float)stud.getGalutinis());

    vector <int> nd1;
    int n1 = 10;
    nd1.push_back(1);
    nd1.push_back(10);
    nd1.push_back(2);
    nd1.push_back(3);
    nd1.push_back(5);
    nd1.push_back(4);
    nd1.push_back(2);
    nd1.push_back(5);
    nd1.push_back(3);
    nd1.push_back(1);
    Studentas stud1(1, "", "", n1, nd1, 5);
    ASSERT_EQ((float)4.2, (float)stud1.getGalutinis());
    
    vector <int> nd2;
    int n2 = 8;
    nd2.push_back(10);
    nd2.push_back(9);
    nd2.push_back(6);
    nd2.push_back(6);
    nd2.push_back(10);
    nd2.push_back(7);
    nd2.push_back(8);
    nd2.push_back(7);
    Studentas stud2(1, "", "", n2, nd2, 5);
    ASSERT_EQ((float)6, (float)stud2.getGalutinis());
}

TEST(StudentasTest1, LygybesTikrinimas) {
    vector <int> nd;
    int n = 5;
    nd.push_back(5);
    nd.push_back(9);
    nd.push_back(6);
    nd.push_back(3);
    nd.push_back(7);
    Studentas stud(1, "", "", n, nd, 8);
    Studentas stud1;
    stud1 = stud;
    ASSERT_EQ(stud, stud1);
}
