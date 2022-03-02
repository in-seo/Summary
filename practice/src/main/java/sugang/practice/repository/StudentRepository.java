package sugang.practice.repository;
import org.springframework.stereotype.Repository;
import sugang.practice.domain.Student;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import java.util.List;


@Repository
public class StudentRepository{
    @PersistenceContext
    EntityManager em;

    public Long save(Student student) {
        em.persist(student);
        return student.getId();
    }
    public Student findById(Long id) {
        return em.find(Student.class, id);
    }

    public List<Student> findByName(String name){
        return em.createQuery("select s from Student s where s.name=:name",Student.class)
                .setParameter("name",name)
                .getResultList();
    }

    public List<Student> findAll(){
        return em.createQuery("select s from Student s",Student.class)
                .getResultList();
    }

}
