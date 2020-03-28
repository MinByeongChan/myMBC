package com.example.demo.dao;

import java.util.List;
import java.util.Map;

import com.example.demo.model.BoardData;
import com.example.demo.model.Criteria;

public interface BoardDAO {
	
	public void write(BoardData boardData) throws Exception;
	
	public void create(BoardData boardData) throws Exception;

	public List<BoardData> list() throws Exception;
	
	// 게시물 수정
	public void update(BoardData boardData) throws Exception;
	
	// 게시물 삭제
	public void delete(int idx) throws Exception;
	
	//Read
	public BoardData read(int idx) throws Exception;
	
	// 게시물 목록 조회
	public List<BoardData> list(Criteria cri) throws Exception;
	
	// 게시물  총 갯수 
	public int listCount() throws Exception;
	
}
