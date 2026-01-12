#include "game.h"
#include <random>
#include <cstdlib>
#include <ctime>

Game::Game() 
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
}

Block Game::GetRandomBlock()
{	
	if(blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randomIndex = std::rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(), JBlock(), TBlock(), OBlock(), LBlock(), SBlock(), ZBlock() };
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw(11,11);
	nextBlock.Draw(270, 270);
}

void Game::HandelInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
		case KEY_LEFT :
			MoveBlockLeft();
			break;
		case KEY_RIGHT :
			MoveBlockRight();
			break;
		case KEY_DOWN :
			MoveBlockDown();
			updateScore(0, 1);
			break;
		case KEY_SPACE:
			RotateBlock();
			break;
	}
}

void Game::MoveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (IsCellOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsCellOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (IsCellOutside() || BlockFits() == false)
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsCellOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if(grid.IsCellOutside(item.row,item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	currentBlock.Rotate();
	if (IsCellOutside())
	{
		currentBlock.UnRotate();
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	} 
	currentBlock = nextBlock;
	if (BlockFits() == false)
	{
		gameOver = true;
		return;
	}
	nextBlock = GetRandomBlock();
	int rowclear = grid.ClearFullRows();
	updateScore(rowclear, 0);
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::Reset()
{
	grid.Initalize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::updateScore(int lineCleared, int moveDownPoints)
{
	switch (lineCleared)
	{
	case 1:
		score += 40;
		break;
	case 2:
		score += 100;
		break;
	case 3:
		score += 300;
		break;
	case 4:
		score += 1200;
		break;
	default:
		break;
	}
	score += moveDownPoints;
}

