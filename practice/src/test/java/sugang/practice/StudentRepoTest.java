package sugang.practice;

import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;
import sugang.practice.domain.Student;
import sugang.practice.repository.StudentRepository;

@RunWith(SpringRunner.class)
@SpringBootTest
@Transactional
public class StudentRepoTest {
    @Autowired
    StudentRepository studentRepository;

    @Test
    @Rollback(false)
    public void 학생테스트() {
        Student student = new Student();
        student.setName("holymoly");
        student.setNumber("B911096");
        Long savedId = studentRepository.save(student);
        System.out.println(savedId);
    }
}