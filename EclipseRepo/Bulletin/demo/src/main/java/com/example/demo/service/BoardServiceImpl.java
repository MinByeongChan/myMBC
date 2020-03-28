package com.example.demo.service;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;

import org.springframework.stereotype.Service;

import com.example.demo.dao.BoardDAO;
import com.example.demo.model.BoardData;
import com.example.demo.model.Criteria;
import com.example.demo.service.BoardService;

@Service
public class BoardServiceImpl implements BoardService {
	
	@Resource
	private BoardDAO dao;

	@Override
	public void write(BoardData boardData) throws Exception {
		dao.write(boardData);
	}

	@Override
	public List<BoardData> list() throws Exception {

		return dao.list();
	}

	@Override
	public void update(BoardData boardData) throws Exception {
		dao.update(boardData);
	}

	@Override
	public void delete(int idx) throws Exception {
		dao.delete(idx);
	}

	@Override
	public BoardData read(int idx) throws Exception {
		return dao.read(idx);
	}

	@Override
	public void create(BoardData boardData) throws Exception {
		dao.create(boardData);
	}

	@Override
	public List<BoardData> list(Criteria cri) throws Exception {
		return dao.list(cri);
	}

	@Override
	public int listCount() throws Exception {
		return dao.listCount();
	}
	
	

}