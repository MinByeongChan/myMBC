package com.example.demo.service;

import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.example.demo.model.BoardData;
import com.example.demo.model.Criteria;

@Service
public interface BoardService {

	// insert
	public void write(BoardData boardData) throws Exception;

	public List<BoardData> list() throws Exception;

	// update
	public void update(BoardData boardData) throws Exception;

	// delete
	public void delete(int idx) throws Exception;

	// read
	public BoardData read(int idx) throws Exception;

	public void create(BoardData boardData) throws Exception;

	// 게시물 목록 조회
	public List<BoardData> list(Criteria cri) throws Exception;

	// 게시물 총 갯수
	public int listCount() throws Exception;
}