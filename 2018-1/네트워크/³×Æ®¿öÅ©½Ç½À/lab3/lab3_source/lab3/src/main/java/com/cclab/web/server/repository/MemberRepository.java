package com.cclab.web.server.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import com.cclab.web.server.domain.Member;

public interface MemberRepository extends JpaRepository<Member, Long> {

}
