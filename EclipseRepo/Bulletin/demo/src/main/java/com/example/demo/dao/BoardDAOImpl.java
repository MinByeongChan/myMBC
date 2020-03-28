package com.example.demo.dao;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;
import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.example.demo.model.BoardData;
import com.example.demo.model.Criteria;

@Repository
public class BoardDAOImpl implements BoardDAO {

	@Resource
	private SqlSession sqlSession;
	
	// 게시글 작성
	@Override
	public void write(BoardData boardData) throws Exception {
		sqlSession.insert("insert", boardData);		
	}

	@Override
	public List<BoardData> list() throws Exception {
		
		return sqlSession.selectList("list");
	}

	@Override
	public void update(BoardData boardData) throws Exception {
		sqlSession.update("update", boardData);
	}

	@Override
	public void delete(int idx) throws Exception {
		sqlSession.delete("delete", idx);
	}

	@Override
	public BoardData read(int idx) throws Exception {
		return sqlSession.selectOne("read", idx);
	}

	@Override
	public void create(BoardData boardData) throws Exception {
		sqlSession.insert("insert", boardData);
	}

	@Override
	public List<BoardData> list(Criteria cri) throws Exception {
		
		return sqlSession.selectList("listPage", cri);
	}

	@Override
	public int listCount() throws Exception {
		
		return sqlSession.selectOne("listCount");
	}
	

}